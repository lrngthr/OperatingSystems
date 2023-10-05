#include  <stdio.h>
#include <stdlib.h>
#include  <sys/types.h>
#include <unistd.h>


#define   MAX_COUNT  30

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid1, pid2;

     pid1 = fork();
     if (pid1 == 0) 
        ChildProcess();
     pid2 = fork();
     if (pid2 == 0)
        ChildProcess();


      ParentProcess();
      ParentProcess();
}

void  ChildProcess(void)
{
     int   i;
     // Seed the random number generator with the current time
      unsigned int seed = (unsigned int)time(NULL);
      srandom(seed);

     for (i = 1; i <= MAX_COUNT; i++)
          printf("   This line is from child, value = %d\n", i);

          pid_t current_pid = getpid();
          printf("Child Pid: %d is going to sleep!\n", current_pid);
          int random_number = random() % 11;
          sleep(random_number);

          pid_t parent_pid = getppid();
          pid_t child_pid = getpid();
          printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n" , child_pid, parent_pid);
     printf("   *** Child process is done ***\n");
     exit(0);

}

void  ParentProcess(void)
{
    int status;
    pid_t terminated_child_pid;


    terminated_child_pid = wait(&status);
    printf("Child Pid: %d has completed", terminated_child_pid);

     printf("*** Parent is done ***\n");
}