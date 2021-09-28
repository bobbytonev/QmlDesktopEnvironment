#ifndef PROGRAMLAUNCHER_H
#define PROGRAMLAUNCHER_H





#include <QObject>
#include <QVariantList>
#include <QSettings>
#include <QQuickStyle>
#include <QDirIterator>
#include <QIcon>
#include <QDebug>
#include <thread>
#include <QProcess>
class ProgramLauncher : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList programs READ programs WRITE setPrograms NOTIFY programsChanged)
	
	
	
	Q_PROPERTY(bool finish READ finish WRITE isFinished NOTIFY finishedChanged)

    const QString  SYSTEM_APPLICATIONS = "/usr/share/applications";
    const QString USER_APPLICATIONS = "%1/.local/share/applications";
	
	

    struct Info{
        QString name,icon{"application"},path;
    }info;


public:


Q_INVOKABLE void eval(QString page,QString arg){
	
	QProcess *process = new QProcess(this);

	process->start("sudo -E /media/sf_DIPLOMNA/QmlSettings/./QmlSettings " + page+" "+arg);
   
	//system(qPrintable("sudo -E /media/sf_DIPLOMNA/QmlSettings/./QmlSettings Apps-page.qml "+process));
    //proc.waitForFinished(3000);
	//QProcess::startDetached("sudo -E /media/sf_DIPLOMNA/QmlSettings/./QmlSettings " + page+" "+arg);
	//proc.close();
	
}



Q_INVOKABLE void eval(QString process,QString name,QString fileName){
 //isFinished(false);

QFile file("/var/lib/pacman/db.lck");
if(file.exists())
	   file.remove();
			 


//std::thread* ptr = new std::thread([process]()
//{
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
	QProcess proc;
    proc.start("pacman --noconfirm -Rsn "+process);
    proc.waitForFinished(3000);
	proc.close();
	QSettings settings(QSettings::NativeFormat,QSettings::UserScope,"kos-default-apps", "Apps");
	settings.beginGroup("Apps");
	QStringList childKeys = settings.childKeys();
          foreach (const QString &childKey, childKeys){
          QVariant var(settings.value(childKey));
			
			if(QString::compare(var.toString().split(",")[0],name , Qt::CaseInsensitive)==0){
				settings.setValue(childKey,"");
				
				
			}
            
          }
		   
			settings.sync();
             settings.endGroup();
			 
		QFile dir;
	   dir.remove("/etc/xdg/autostart/"+fileName);
			 
	
			 
	//isFinished(true);
	isFinished(true);
	emit finishedChanged();
	
	
	



    }

Q_INVOKABLE void  startupApps(){
	qDebug()<<"STARTING...";
	 std::thread* ptr = new std::thread([]()
	{
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
	QString STARTUP_APPS = "/etc/xdg/autostart";
    QDirIterator it(STARTUP_APPS, {"*.desktop"}, QDir::NoFilter, QDirIterator::Subdirectories);
	QString path;

	while (it.hasNext()) {
              QString filename = it.next();
              QSettings desktopFile(filename, QSettings::IniFormat);
              desktopFile.beginGroup("Desktop Entry");
              path = desktopFile.value("Exec").toString().remove("\"").remove(QRegExp(" %."));
			  
             QProcess proc;
			proc.startDetached(path);
			proc.close();
			   
	}
	
	});
ptr->join();

delete ptr;
	
	
	
}
    QVariantList reload(){

        QDirIterator it(SYSTEM_APPLICATIONS, {"*.desktop"}, QDir::NoFilter, QDirIterator::Subdirectories);
           QVariantList ret;

           while (it.hasNext()) {
               QString filename = it.next();
                QSettings desktopFile(filename, QSettings::IniFormat);
                desktopFile.beginGroup("Desktop Entry");
              info.path = desktopFile.value("Exec").toString().split(" ")[0];
              info.icon = desktopFile.value("Icon", "application").toString();
               info.name = desktopFile.value("Name").toString();

               //QIcon icon = QIcon::fromTheme(info.icon);
               //if(!icon.isNull()){
				  // QIcon icon = QIcon::fromTheme(info.icon);
				 //QString split =info.name;
              // QStringList nameFormat=split.split(" ");
              
               
              // if(nameFormat.size()>2){
                  // for(int i=2;i<nameFormat.size();i++){
                   // nameFormat.removeLast();
                   //}
              // }
              // info.name=nameFormat.join(" ");

			//if(!icon.isNull())//{
				ret.append(QStringList{info.name, info.icon, info.path,filename});
			//}
               // ret.append(QStringList{info.name, info.icon, info.path});
				
                desktopFile.endGroup();

               }

                return ret;
           }





 void isFinished(const bool &a) {
        if (a != m_finish) {
            m_finish = a;
            emit finishedChanged();
        }
    }
   bool finish() const {
        return m_finish;
    }


    void setPrograms(const QVariantList &a) {
        if (a != m_programs) {
            m_programs = a;
            emit programsChanged();
        }
    }
   QVariantList programs() const {
        return m_programs;
    }
signals:
    void programsChanged();
	   void finishedChanged();


public slots:
    void settings(const QString& str)
    {
        Q_UNUSED(str)
       setPrograms(reload());
    }
private:
    QVariantList m_programs;
	  bool m_finish;
};




#endif // PROGRAMLAUNCHER_H
