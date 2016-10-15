#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	// Parent Process
	if(fork() != 0){
		// Wait Call example
		wait((int *) 0);
		// Kill Call example & getpid example
		kill(getpid(), SIGINT);
	}
	// Child Process
	else{
		// getppid Call example
		printf("Parent process id: %i\n", getppid());
		// exec call example
		execl("/bin/ls", "ls", "-l", (char *)0);
		fprintf (stderr, "exec failed!\n");
		// exit call example
		exit(1);
	}
	exit(0);
}