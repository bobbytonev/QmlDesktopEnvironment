#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "colormanager.h"
#include "ProgramLauncher.h"


#include <QFileSystemWatcher>
#include <QQuickStyle>
#include <QQmlContext>
#include <QFileInfo>


#include <QX11Info>
#include <QWindow>
#include <QQmlEngine>

#include "WindowManager.h"
#include "imageprovider.h"
#include "procces.h"
#include "ThemeManager.h"
void setWindowAtributes(Display* d, int id) {
    Window w = id;

	Atom wmNetWmType = XInternAtom(d, "_NET_WM_WINDOW_TYPE", 1);
    Atom wmTypeDesktop = XInternAtom(d, "_NET_WM_WINDOW_TYPE_DESKTOP", 1);



    XChangeProperty(d, w, wmNetWmType, XA_ATOM, 32, PropModeReplace, (const uchar*)&wmTypeDesktop, 1);
	
	 Atom wmNetWmState = XInternAtom(d, "_NET_WM_STATE", 1);
	
	
    Atom wmStateBelow = XInternAtom(d, "_NET_WM_STATE_BELOW", 1);
	XClientMessageEvent xclient;
    memset(&xclient, 0, sizeof xclient);

    xclient.type = ClientMessage;
    xclient.window = w;
    xclient.message_type = wmNetWmState;
    xclient.format = 32;
    xclient.data.l[0] = _NET_WM_STATE_ADD;
    xclient.data.l[1] = wmStateBelow;
	XSendEvent(d, DefaultRootWindow(d), False, SubstructureRedirectMask | SubstructureNotifyMask, (XEvent*)&xclient);

    


}

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

   
   QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
   // QQuickStyle::setStyle("C:/Users/Test/Documents/DarkNeon");
    
	 engine.addImageProvider("icons", new ImageProvider());
	
	
	//theme watcher
	QSettings themeConfigSettings(QSettings::NativeFormat,QSettings::UserScope,"theme-config", "Theme");
	QString theme_config_dir = QFileInfo(themeConfigSettings.fileName()).absolutePath() + "/";
	QFileSystemWatcher themeConfigWatcher;
	themeConfigWatcher.addPath(theme_config_dir);
	
	ThemeManager themeManager;
	
    engine.rootContext()->setContextProperty("tcm", &themeManager);
    themeManager.setTheme(themeManager.reload());  
	QObject::connect(&themeConfigWatcher,SIGNAL(directoryChanged(QString)),&themeManager,SLOT(settings(QString)));
 
	//end
	
	QQuickStyle::setStyle("/usr/share/themes/"+themeManager.theme[1].toString());
	
	
	
	
	WindowManager manager;
	manager.start();//starting window manager
	engine.rootContext()->setContextProperty("windowManager", &manager);
	
	QSettings settings(QSettings::NativeFormat,QSettings::UserScope,QQuickStyle::name(), "Themes");

	QString config_dir = QFileInfo(settings.fileName()).absolutePath() + "/";
	QFileSystemWatcher watcher;
    watcher.addPath(config_dir);

	
	//init color manager
	ColorManager msg;
    engine.rootContext()->setContextProperty("msg", &msg);
    msg.setColors(msg.reload());
	QObject::connect(&watcher,SIGNAL(directoryChanged(QString)),&msg,SLOT(settings(QString)));
	
	
	
	
	///init program launcher
	QFileSystemWatcher programWatcher;
     programWatcher.addPath("/usr/share/applications");
     
	 ProgramLauncher programs;
     engine.rootContext()->setContextProperty("launcher", &programs);
     programs.setPrograms(programs.reload());
    
	QObject::connect(&programWatcher,SIGNAL(directoryChanged(QString)),&programs,SLOT(settings(QString)));
	engine.rootContext()->setContextProperty("launch", new Procces(&engine));	


	
             app.setOrganizationName("KOS");
             app.setOrganizationDomain("kos.com");
             app.setApplicationName("DesktopEnviroment");



	engine.load(url);
	
	QObject* m_rootObject = engine.rootObjects().first();
    QWindow* w = qobject_cast<QWindow*>(m_rootObject);
	
	
	manager.setOwnerId(w->winId());

    Display* d = QX11Info::display();
	setWindowAtributes(d, w->winId());



    return app.exec();
}
