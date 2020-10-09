#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

void copy(int, int);
void display(int);

int main(int argc, char *argv[])
{
	int fold, fnew;
	if(argc != 3)
	{
		printf("\nTwo Arguments Reqiured!\n");
		exit(1);
	}
	fold = open(argv[1], 0);
	if(fold == -1)
	{
		printf("\nUnable to open the file: %s\n", argv[1]);
		exit(1);
	}
	fnew = creat(argv[2], 0666);
	if(fnew == -1)
	{
		printf("\nUnable to Create the File: %s\n", argv[2]);
		exit(1);
	}
	copy(fold, fnew);
	close(fold);
	close(fnew);
	
	fnew = open(argv[2], 0);
	printf("\nNew File:\n");
	display(fnew);
	close(fnew);
	
	exit(0);
}

void copy(int old, int fnew)
{
	int count = 0;
	char buffer[512];
	while((count = read(old, buffer, sizeof(buffer))) > 0)
	{
		write(fnew, buffer, count);
	}
}

void display(int fnew)
{
	int count = 0, i;
	char buffer[512];
	while((count = read(fnew, buffer, sizeof(buffer))) > 0)
	{
		for(i=0; i<count; i++)
		{
			printf("%c", buffer[i]);
		}
	}
	printf("\n");
}
