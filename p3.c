#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t id1 = fork();
	pid_t id2 = fork();

	if (id1 > 0 && id2 > 0)
	{
		wait(NULL);
		wait(NULL);
		printf("Parent terminated\n");
	}

	else if (id1 == 0 && id2 > 0)
	{
		sleep(2);
		wait(NULL);
		printf("1st child terminated\n");
	}

	else if (id1 > 0 && id2 == 0)
	{
		sleep(1);
		printf("2nd child terminated\n");
	}
	else
	{
		printf("grand child terminated\n");
	}
	return 0;
}
