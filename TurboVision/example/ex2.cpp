// Example 1

#define Uses_TApplication
#define Uses_TMenuBar
#define Uses_TSubMenu
#define Uses_TRect
#define Uses_TKeys

#include <tvision/tv.h>

#include <stdlib.h>

class TMyApp : public TApplication
{
public:
  TMyApp(int argc, char **argv);

  static TMenuBar *initMenuBar(TRect);
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

int main(int argc, char *argv[])
{
  MyApp myApp(argc, argv);

  myApp.run();
  myApp.shutDown();

  return EXIT_SUCCESS;
}
