#include "widget.h"

#include <QApplication>
#include <QList>
#include <QObject>


#include <QList>
#include <QDebug>

// X11 一种可能性是添加 QTextStream 包含该错误出现的位置。

// 至于 X11 相关的错误，请尝试将 X11 包含在 Qt 包含之后。
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/X.h>
#include <unistd.h>

// https://www.jianshu.com/p/c906fbe1ad00
// https://stackoverflow.com/questions/1201179/how-to-identify-top-level-x11-windows-using-xlib
// https://www.cnblogs.com/alalazy/p/12323089.html
class WindowsMatchingPid
{
public:
    WindowsMatchingPid(Display *display, Window wRoot, unsigned long pid)
        : _display(display)
        , _pid(pid)
    {
        _atomPID = XInternAtom(display, "_NET_WM_PID", True);
        if(_atomPID == None)
        {
            return;
        }

        search(wRoot);
    }

    const QList<Window> result() const { return _result; }

private:
    unsigned long  _pid;
    Atom           _atomPID;
    Display       *_display;
    QList<Window>   _result;

    void search(Window w)
    {
        Atom           type;
        int            format;
        unsigned long  nItems;
        unsigned long  bytesAfter;
        unsigned char *propPID = 0;
        if(Success == XGetWindowProperty(_display, w, _atomPID, 0, 1, False, XA_CARDINAL,
                                         &type, &format, &nItems, &bytesAfter, &propPID))
        {
            if(propPID != 0)
            {
                if(_pid == *((unsigned long *)propPID))
                    _result.append(w);
                XFree(propPID);
            }
        }

        Window    wRoot;
        Window    wParent;
        Window   *wChild;
        unsigned  nChildren;
        if(0 != XQueryTree(_display, w, &wRoot, &wParent, &wChild, &nChildren))
        {
            for(unsigned i = 0; i < nChildren; i++)
                search(wChild[i]);
        }
    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();

    QList<QObject*> m_pformList;

    int pid = getpid();
    Display *display = XOpenDisplay(0);
    WindowsMatchingPid match(display, XDefaultRootWindow(display), pid);
    const QList<Window> result = match.result();
    for(int i=0; i<result.count();i++)
    {
        unsigned long winId = (unsigned long)(result.at(i));
        QWidget* win = QWidget::find(winId);
        if(win!=NULL&&win->isWindow()&&win->isVisible()){
            m_pformList.append((QObject*)win);
        }
    }

    XCloseDisplay(display);

    return a.exec();
}
