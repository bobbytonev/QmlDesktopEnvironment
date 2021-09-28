
#include <QThread>
#include <QVariant>
#include <QDebug>
#include <QSettings>

#include <QX11Info>
extern "C" {
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <X11/Xproto.h>
#include <X11/extensions/XTest.h>
#define _NET_WM_STATE_ADD 1
}
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define Y 30
#define HEIGHT 50






class WindowManager : public QThread
{
    Q_OBJECT
	
	
	long ownerId=-1;
	
	
	Q_PROPERTY(QVariantList data  READ data WRITE setData NOTIFY dataWindowChanged)

	
	
	//long activeWindow;
	
	QVariantList m_data;
	//QList<QString> m_dataName;
	
	//test
	
	struct WindowAattributes{
		
		long id;
		QString name;
		QString imagePath;
		long dialog;
		
		
		
		
		
	};
	
	
	//test
	QList<long> dialogs;
	
	//end
	
	
	//end-test
	
	
	Display * dpy;
    XWindowAttributes attr;
    XButtonEvent xButtonStart;
    XEvent ev;
	int snum; 
    int  width;
    int  height;
	
	int flag=0;
	
	XSetWindowAttributes attributes;
	Window win;	
	

	Bool allwaysOnTop=false;
	
	Window desktopID=NULL;





Q_INVOKABLE void reload(){
	setData(m_data);
}


void setData(const QVariantList &a) {
        if (a != m_data) {
           m_data = a;
            emit dataWindowChanged();
        }
    }
   
  QVariantList data() const {
        return m_data;
    }


public:
signals:
    void dataWindowChanged();

public:
static int handler(Display * d, XErrorEvent * e)
{
   
	
	printf("Error code: %d ",e->error_code);
    return 0;
}
	
int dublicate(long id){
	for(int i=0;i<m_data.size();i++){
		if(m_data[i].toStringList()[0].toLong()==id) return 1;
		
	}
	return 0;
}

void setOwnerId(long ownerId){
	this->ownerId=ownerId;
}
char* windowType(Display* dpy,Window window){

	Atom type;
	Atom wmNetWmType = XInternAtom(dpy, "_NET_WM_WINDOW_TYPE", 1);
	unsigned long len, bytes_left, dummy;
	int format; //result;
	unsigned char *data;

	XGetWindowProperty (dpy,window,wmNetWmType,0, 0,False,AnyPropertyType,&type,&format,&len,&bytes_left,&data);
	
	XGetWindowProperty (dpy, window, wmNetWmType, 0, bytes_left, 0, XA_ATOM, &type, &format, &len, &dummy, &data);
	Atom atom=((Atom*)data)[0];
	return XGetAtomName(dpy,atom);
}

void  deleteFromList(long id){
	for(int i=0;i<m_data.size();i++){
		if(m_data[i].toStringList()[0].toLong()==id){ m_data.removeAt(i); break;};
		
	}
	emit dataWindowChanged();
	
		
		
}
//void removeDialog(long id){
	//for(int i=0;i<dialogs.size();i++){
		//if(dialogs[i])==id){ dialogs.removeAt(i); break;};
		
	//}
//}

Q_INVOKABLE void minimize(){
	for(int i=0;i<dialogs.size();i++){
		
		XUnmapWindow(dpy, dialogs[i]);
		
		XFlush(dpy);
		
		
	}
	dialogs.clear();
	
	for(int i=0;i<m_data.size();i++){
		
		XUnmapWindow(dpy, m_data[i].toStringList()[0].toLong());
		
		XFlush(dpy);
	
		
	}
	
	
		
	
}
Q_INVOKABLE void back(){
	//this function click mouse 5 in center of the screen
	Display *d=QX11Info::display();
	Window root = DefaultRootWindow(d);
	
	Window root_window; //<--one
    int root_x, root_y; //<--two
    unsigned int mask; //<--three
	
	XQueryPointer(d, DefaultRootWindow(d), &root_window, &root_window, &root_x, &root_y, &root_x, &root_y, &mask); 
	XWarpPointer(d, None, root, 0, 0, 0, 0, DisplayWidth(d,0)/2, DisplayHeight(d,0)/2);
	XTestFakeButtonEvent(d, 8, True, CurrentTime);
	XTestFakeButtonEvent(d, 8, False, CurrentTime);
	XWarpPointer(d, None, root, 0, 0, 0, 0,root_x+1, root_y+1);
		
	}
//NEED TO BE OPTIMIZED
/*
int indexOf(long id){
		for(int i=0;i<m_data.size();i++){
		if(m_data[i].toStringList()[0].toLong()==id){ return i;};
		
	}
	
	return 0;
}
*/

Q_INVOKABLE void restoreWindow(long id,int index){
		
		XMapWindow(dpy, id);
		XRaiseWindow(dpy,id);
		
		
		//m_data.append(id);
		//emit dataWindowChanged();
		//m_dataName.move(m_data.lastIndexOf(id), m_data.count()-1);
		//qDebug()<<m_dataName[0];
		//if(index!=0||index!=m_data.count()-1){
		m_data.move(index, m_data.count()-1);
		emit dataWindowChanged();
		//}
		
		
		XFlush(dpy);
		
		
	
}
Q_INVOKABLE void killWindow(long id){
		XDestroyWindow(dpy, id);
		
		XFlush(dpy);
	
}
Q_INVOKABLE void killAllWindows(){
		for(int i=0;i<m_data.size();i++){
		XDestroyWindow(dpy, m_data[i].toStringList()[0].toLong());
		XFlush(dpy);
		}
}



Q_INVOKABLE void setAllwaysOnTop(Bool allwaysOnTop ){
		this->allwaysOnTop=allwaysOnTop;
		
		qDebug()<<"Allways on Top"<<allwaysOnTop;
		
		 if(allwaysOnTop==true){
			XRaiseWindow(dpy,desktopID);
			
		 }else{
		 XLowerWindow(dpy,desktopID);
		 }
		 XFlush(dpy);
}

Q_INVOKABLE void setOnTop(Bool onTop){
	if(onTop){
		XRaiseWindow(dpy,desktopID);
	}else{
		 XLowerWindow(dpy,desktopID);
		 
	}
	 XFlush(dpy);
}


QString  getWindowName(long id){
	
	 Atom prop = XInternAtom(dpy,"_NET_WM_NAME",False), type;
	  Atom prop2 = XInternAtom(dpy,"WM_CLASS",False);
    int form;
    unsigned long remain, len;
    unsigned char *list;


    if (XGetWindowProperty(dpy,id,prop,0,1024,False,AnyPropertyType,
                &type,&form,&len,&remain,&list) != Success) {

        return NULL;
    }else if(XGetWindowProperty(dpy,id,prop2,0,1024,False,AnyPropertyType,
                &type,&form,&len,&remain,&list) != Success){
			return NULL;
	}
	//XFlush(dpy);
	
    return QString::fromLocal8Bit((char*)list);
}

/*
void restore(Display* dpy){
	for(int i=0;i<m_data.size();i++){
		//XIconifyWindow(dpy, head->a.id, 0);
		XMapWindow(dpy, m_data.at(i));
		
	}
}
*/
	
	
			WindowManager(){
					
				if(!(dpy = XOpenDisplay(0x0))){ exit(1); }
				
				snum= DefaultScreen(dpy);
				width = DisplayWidth(dpy, snum);
				height= DisplayHeight(dpy, snum);
				
				attributes.event_mask =PropertyChangeMask | SubstructureNotifyMask | StructureNotifyMask | FocusChangeMask ;
				win = XDefaultRootWindow(dpy);
				XChangeWindowAttributes(dpy, win, CWEventMask, &attributes);
				
				 XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("F1")), Mod1Mask,
				DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
			XGrabButton(dpy, 1, Mod1Mask, DefaultRootWindow(dpy), True,
            ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);
			XGrabButton(dpy, 3, Mod1Mask, DefaultRootWindow(dpy), True,
            ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);

			xButtonStart.subwindow = None;
			XSetErrorHandler(&handler);
			XSynchronize(dpy,False );

			}
			


protected:
    void run(){
		
		for(;;){
			
			
		
		 XNextEvent(dpy, &ev);
		 
		 if(ev.type==DestroyNotify&&ev.xdestroywindow.window!=None){
			
			deleteFromList(ev.xdestroywindow.window);
			
			
				
			
		}
		else if(ev.type==MapNotify){
			if(dublicate((long)ev.xmap.window)==0){
			//if(strcmp("_NET_WM_WINDOW_TYPE_NORMAL",windowType(dpy,ev.xmap.window))==0){
			XMoveResizeWindow(dpy, ev.xmap.window, 0, Y, width, height-(HEIGHT+Y));
			
			if(strcmp("_NET_WM_WINDOW_TYPE_DIALOG",windowType(dpy,ev.xmap.window))==0){
				XRaiseWindow(dpy,ev.xmap.window);
				XFlush(dpy);
				dialogs.append((long)ev.xmap.window);
				
				
			
			}else{
			//activeWindow=(long)ev.xmap.window;
			WindowAattributes wa;
			wa.id=(long)ev.xmap.window;
			wa.name=getWindowName((long)ev.xmap.window);
			wa.dialog=0;
			
			
			m_data.append(QStringList{QString::number(wa.id), wa.name});
			emit dataWindowChanged();
			}

			//if(allwaysOnTop==true)
				//XRaiseWindow(dpy,desktopID);
			
			
						
						//m_data[i].toStringList()[0].toLong()==id

			//}	

			
			if(allwaysOnTop==true){
				XRaiseWindow(dpy,desktopID);
				
				
			}
		
			
			
						
			}
			
			 XFlush(dpy);
			
			
			
			
			
		}
		
		 if(ev.type==UnmapNotify ){
				//printf("%ld",ev.xunmap.window);
				
				//puts(" ");
				
				//if(strcmp("_NET_WM_WINDOW_TYPE_DIALOG",windowType(dpy,ev.xunmap.window))==0){
					
					//deleteFromList(ev.xunmap.window);
					
				//}
				
				
		}

		 if(ev.type==ClientMessage){
				
				if(strcmp("_NET_WM_WINDOW_TYPE_DESKTOP",windowType(dpy,ev.xclient.window))==0&&desktopID==NULL){
					XMoveResizeWindow(dpy, ev.xclient.window, 0, 0, width, height);
					XLowerWindow(dpy,ev.xclient.window);
					XSync(dpy,0);
					deleteFromList((long)ev.xclient.window);
					
					desktopID=ev.xclient.window;
				}
				 else if(strcmp("_NET_WM_WINDOW_TYPE_DOCK",windowType(dpy,ev.xclient.window))==0){
					XMoveResizeWindow(dpy, ev.xclient.window, 0, height-80, width, 80);
					
					deleteFromList((long)ev.xclient.window);
				}
				else if(strcmp("_NET_WM_WINDOW_TYPE_MENU",windowType(dpy,ev.xclient.window))==0){
					
					
					deleteFromList((long)ev.xclient.window);
				}
				
				if(ev.xclient.data.l[1]==539){//MINIMIZE CODE
					//if(flag==0){
					minimize();
					//flag=1;
					//}else{
						//restore(dpy);
					//flag=0;
					//}
				}
					
				
			
				//puts("");
				//printf("%ld",ev.xclient.data.l[1]);
					//if(ev.xclient.data.l[0]==1&&(ev.xclient.data.l[1]==400)){
							
							//XLowerWindow(dpy,ev.xclient.window);
							
							//XSync(dpy,0);
							
					//}
		}
	
		
		else if( ev.type==PropertyNotify ){
			qDebug()<<"HERE";
			
		}
		else if(ev.type == KeyPress && ev.xkey.subwindow != None){
            XRaiseWindow(dpy, ev.xkey.subwindow);
			
        }else if(ev.type == ButtonPress && ev.xbutton.subwindow != None)
        {
            XGetWindowAttributes(dpy, ev.xbutton.subwindow, &attr);
            xButtonStart = ev.xbutton;
			XSetInputFocus(dpy,ev.xbutton.window,RevertToParent,CurrentTime);
			XFlush(dpy);
			
        }
        else if(ev.type == MotionNotify && xButtonStart.subwindow != None)
        {
			
			//if(strcmp("_NET_WM_WINDOW_TYPE_NORMAL",windowType(dpy,start.subwindow))==0){
            int xdiff = ev.xbutton.x_root - xButtonStart.x_root;
            int ydiff = ev.xbutton.y_root - xButtonStart.y_root;
            XMoveResizeWindow(dpy, xButtonStart.subwindow,
                attr.x + (xButtonStart.button==1 ? xdiff : 0),
               attr.y + (xButtonStart.button==1 ? ydiff : 0),
                MAX(1, attr.width + (xButtonStart.button==3 ? xdiff : 0)),
                MAX(1, attr.height + (xButtonStart.button==3 ? ydiff : 0)));
				//printList(head);
			//}
				
				
        }
		
        else if(ev.type == ButtonRelease){
		//XDestroyWindow(dpy, start.subwindow); 
            xButtonStart.subwindow = None;
		}
		
		}
		
		
	}
};

