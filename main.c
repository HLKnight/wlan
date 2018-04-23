#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "wifi.h"

int main(void)
{
	int ret;
	// run a while(1) loop
	while(1)
	{
		ret=system(COMMAND);
		// run system command "iwlist | egrep > scan.txt"
		if(WIFSIGNALED(ret) && (WTERMSIG(ret)==SIGINT))
		{
			break;
		}
		// open scan.txt file to process data
		process("scan.txt");
#ifdef DEBUG
		break;
#else
		sleep(3);
#endif
		// display network on screen
		// if communication is defined, send data to a webserver
	}
}
