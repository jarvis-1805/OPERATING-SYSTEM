/*
 * Write a program (using fork() and/or exec() commands)
 * where parent and child execute: 
 *  (a) same program, same code
 *  (b) same program, different code
 *  (c) different programs
 *  (d) before terminating, the parent waits for the child
 *      to finish its task.
 */

#include <iostream>
#include <unistd.h>

using namespace std;

void diffProgram()
{
  pid_t pidFork;
  pidFork = fork();
  if(pidFork < 0)
    cout << "\nError in fork...";
  else if(pidFork == 0)
    execlp("/bin/ls", "ls\n", NULL);
  else
    execlp("/usr/bin/cal", "cal\n", NULL);
  return;
}

int main()
{
  diffProgram();
}