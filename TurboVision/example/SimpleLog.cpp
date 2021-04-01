// Log, version 0.1: a simple logging class
// From : https://www.drdobbs.com/cpp/logging-in-c/201804215
//

#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <ctime>

enum TLogLevel {
  logERROR, 
  logWARNING, 
  logINFO, 
  logDEBUG, 
  logDEBUG1,
  logDEBUG2, 
  logDEBUG3, 
  logDEBUG4
};

class Log
{
public:
  Log();
  virtual ~Log();
  std::ostringstream& Get(TLogLevel level = logINFO);
public:
  static TLogLevel& ReportingLevel();
protected:
  std::ostringstream os;
private:
  Log(const Log&);
  Log& operator =(const Log&);
private:
  TLogLevel messageLevel;
};

std::ostringstream& Log::Get(TLogLevel level)
{
  os << "- " << NowTime();
  os << " " << ToString(level) << ": ";
  os << std::string(level > logDEBUG ? 0 : level - logDEBUG, '\t');
  messageLevel = level;
  return os;
}

Log::~Log()
{
  if (messageLevel >= Log::ReportingLevel())
  {
    os << std::endl;
    fprintf(stderr, "%s", os.str().c_str());
    fflush(stderr);
  }
}


int main(void)
{
  Log::ReportingLevel() = logDEBUG2;
  const int count = 3;
  Log().Get(logDEBUG) << "A loop with "    << count << " iterations";
  for (int i = 0; i != count; ++i)
  {
    Log().Get(logDEBUG1)        << "the counter i = " << i;
  }


  return EXIT_SUCCESS;
}
