/*
* Write a program to print file details including owner access permissions, file
* access time, where filename is given as argument.
*/

#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc, char *argv[3])
{
  int i;
  struct stat buffer;
  printf("\nGiven File Name: ");
  for(i=1; i<argc; i++)
  {
    printf("%s", argv[i]);
    if(stat(argv[i], &buffer) < 0)
      printf("\nError in File started");
    else
    {
      printf("\nOwnered: %d\ngid: %d", buffer.st_uid, buffer.st_gid);
      printf("\nAccess Permission: %d", buffer.st_mode);
      printf("\nAccess Time: %ld\n", (time(&(buffer.st_atime))));
    }
  }
}