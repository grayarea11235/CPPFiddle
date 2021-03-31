// Example 1

#define Uses_TApplication

#include <tvision/tv.h>

#include <stdlib.h>

class TMyApp : public TApplication
{
public:
  TMyApp(int argc, char **argv);

};

TMyApp::TMyApp(int argc, char *argv[]) : 
    TProgInit( TMyApp::initStatusLine,
               TMyApp::initMenuBar,
               TMyApp::initDeskTop
    ), TApplication()
{
    TCommandSet ts;
    ts.enableCmd( cmSave );
    ts.enableCmd( cmSaveAs );
    ts.enableCmd( cmCut );
    ts.enableCmd( cmCopy );
    ts.enableCmd( cmPaste );
    ts.enableCmd( cmClear );
    ts.enableCmd( cmUndo );
//    ts.enableCmd( cmFind );
//    ts.enableCmd( cmReplace );
//    ts.enableCmd( cmSearchAgain );
    disableCommands( ts );

}

int main(int argc, char *argv[])
{
  TMyApp myApp(argc, argv);

  myApp.run();
  myApp.shutDown();

  return EXIT_SUCCESS;
}
