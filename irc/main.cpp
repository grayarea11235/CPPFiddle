#include <iostream>
#include <thread>

class IrcClient
{
  public:
    IrcClient();
  
  private:
  

};


IrcClient::IrcClient()
{

}


void listen_thread()
{
}


int main(int argv, char *argc[])
{
  std::thread listen(listen_thread);
  
  IrcClient *ircClient = new IrcClient();

  listen.join();

  std::cout << "Starting test\n";
}
