// Example 1

#define Uses_TApplication
#define Uses_TMenuBar
#define Uses_TSubMenu
#define Uses_TRect
#define Uses_TKeys
#define Uses_TEditor
#define Uses_TFileEditor
#define Uses_TFileDialog
#define Uses_TEditWindow
#define Uses_TDeskTop

#include <tvision/tv.h>

#include <stdlib.h>

class TMyApp : public TApplication
{
public:
  TMyApp(int argc, char **argv);

  virtual void handleEvent(TEvent& event);
  static TMenuBar *initMenuBar(TRect);
  
  TEditWindow *openEditor(const char *fileName, Boolean visible);
  void fileOpen();
};

TMenuBar *TMyApp::initMenuBar(TRect r)
{
  TSubMenu& sub1 = *new TSubMenu( "~F~ile", kbAltF ) + 
    *new TMenuItem("~O~pen", cmOpen, kbF3, hcNoContext, "F4") +
    *new TMenuItem("E~x~it", cmQuit, kbCtrlQ, hcNoContext, "Ctrl-Q");

  return new TMenuBar(r, sub1);
}

TMyApp::TMyApp(int argc, char *argv[]) : 
    TProgInit( TMyApp::initStatusLine,
               TMyApp::initMenuBar,
               TMyApp::initDeskTop
    ), TApplication()
{

}

ushort execDialog( TDialog *d, void *data )
{
    TView *p = TProgram::application->validView( d );
    if( p == 0 )
        return cmCancel;
    else
        {
        if( data != 0 )
            p->setData( data );
        ushort result = TProgram::deskTop->execView( p );
        if( result != cmCancel && data != 0 )
            p->getData( data );
        TObject::destroy( p );
        return result;
        }
}


TEditWindow *TMyApp::openEditor(const char *fileName, Boolean visible)
{
  TRect r = deskTop->getExtent();
  TView *p = validView(new TEditWindow(r, fileName, wnNoNumber));
  if(!visible)
  {
    p->hide();
  }
  deskTop->insert(p);
  return (TEditWindow *)p;
}

void TMyApp::fileOpen()
{
    char fileName[MAXPATH];
    strcpy(fileName, "*.*");

    if(execDialog(new TFileDialog("*.*", "Open file",
				  "~N~ame", fdOpenButton, 100 ), fileName) != cmCancel)
    {
      openEditor(fileName, True);
    }
}

void TMyApp::handleEvent(TEvent& event)
{
  TApplication::handleEvent( event );
  if( event.what != evCommand )
    return;
  else
    switch( event.message.command )
    {
    case cmOpen:
      fileOpen();
      break;

    case cmNew:
      //fileNew();
      break;

    // case cmChangeDrct:
    //   changeDir();
    //   break;

    // case cmShowClip:
    //   //showClip();
    //   break;

    default:
      return ;
    }
  clearEvent( event );
}


int main(int argc, char *argv[])
{
  TMyApp myApp(argc, argv);

  myApp.run();
  myApp.shutDown();

  return EXIT_SUCCESS;
}
