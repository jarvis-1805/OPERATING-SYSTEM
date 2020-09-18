#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	printf("\nKernel Version:\n");
	system("cat /proc/sys/kernel/osrelease");		//system command to get kernel version

	printf("\nCPU type & Model:\n");
	system("cat /proc/cpuinfo | awk 'NR==5 {print}'");	//system command to get CPU info

	return 0;
}
