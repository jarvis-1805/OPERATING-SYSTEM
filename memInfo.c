#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	printf("\nMemory Information:\n");
	system("cat /proc/meminfo | awk 'NR==1, NR==3 {print}'");	//system command to get Memory Information

	return 0;
}
