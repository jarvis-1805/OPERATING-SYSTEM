#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
  int pid, ppid;

  fork();
  fork();
  fork();

  pid = getpid();
  ppid = getppid();

  if(pid > 0 || ppid > 0)
    wait(NULL);

  cout << "Hello World! " << getppid() << " " << getpid() << endl;
} 