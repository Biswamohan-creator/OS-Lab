//Prog1
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() 
{
	int p, q, r;
	p = fork();
	q = fork();
	r = fork();
	if(p == 0 && q == 0)
		fork();
	printf("%d\n", getpid());
	return 0;
}

//Prog2
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() 
{
    for (int i = 0; i < 6; i++)
    {
        int p = fork();
        if(p == 0)
            exit(0);
        printf("%d\n", getpid());
    }
    return 0;
}

//Prog3
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() 
{
    for (int i = 0; i < 5; i++)
    {
        int q = fork();
        if(q == 0)
        {
            printf("Child process => PPID = %d, PID = %d\n", getppid(), getpid());
            exit(0);
        }
        else
        {
            printf("Parent process => PID = %d\n", getpid());
            printf("Waiting for child process to finish\n");
            sleep(1);
            printf("Child process finished\n");
        }
    }
    return 0;
}