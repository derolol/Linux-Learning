#include "my.h"

// 1. process tree and wait relation
// 2. father build file write
// 3. generate

int main()
{
	FILE *fp;
	pid_t pid1, pid2, pid11, pid21;
	struct tm *t;

	fp = fopen("./log.dat", "w");

	pid1 = fork();
	
	if (pid1 < 0)
	{
		perror("Fork1 wrong!\n");
		exit(-1);
	}
	else if (pid1 == 0)
	{
		pid11 = fork();

		if (pid11 < 0)
		{
			perror("Fork11 wrong!\n");
			exit(-1);
		}
		else if (pid11 == 0)
		{
			printInfo("child11");
			writeInfo(fp, "child11");			
			//fprintf(fp, "child11 : pid = %d exit time = %s\n", getpid(), getCurrentTime());
			exit(0);
		}
		else
		{
			waitpid(pid11, 0, 0);
			printInfo("child1");
			writeInfo(fp, "child1");
			//fprintf(fp, "child1 : pid = %d exit time = %s\n", getpid(), getCurrentTime());
			exit(0);
		}
	
	}
	else
	{

		pid2 = fork();
		
		if (pid2 < 0)
		{
			perror("Fork2 wrong!\n");
			exit(-1);
		}
		else if (pid2 == 0)
		{

			pid21 = fork();
			
			if (pid21 < 0)
			{
				perror("Fork21 wrong!\n");
				exit(-1);
			}
			else if (pid21 == 0)
			{
				printInfo("child21");
				writeInfo(fp, "child21");
				//fprintf(fp, "child21 : pid = %d exit time = %s\n", getpid(), getCurrentTime());
				exit(0);
			}
			else
			{
				waitpid(pid21, 0, 0);
				printInfo("child2");
				writeInfo(fp, "child2");
				//fprintf(fp, "child2 : pid = %d exit time = %s\n", getpid(), getCurrentTime());
				exit(0);
			}
		}
		else
		{
			waitpid(pid1, 0, 0);
			waitpid(pid2, 0, 0);
			printInfo("father");
			writeInfo(fp, "father");
			//fprintf(fp, "father : pid = %d exit time = %s\n", getpid(), getCurrentTime());

			fclose(fp);
			return 0;
		}
	}
}
