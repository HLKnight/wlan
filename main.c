#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "wifi.h"

int main(void)
{
	int ret;
	while(1)
	{
		// Scan for WLANs and stored in "scan.txt" file
		ret=system(COMMAND);
		// If Ctrl+C is pressed
		if(WIFSIGNALED(ret) && (WTERMSIG(ret)==SIGINT))
		{
			break;
		}
		// Open "scan.txt" file to process data
		process("scan.txt");
#ifdef DEBUG
		break;	// break the while loop
#else
		sleep(3);	// sleep for 3 seconds
#endif
	}
}
