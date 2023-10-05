/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int alarm_counter =0;
time_t begin_time;

void handler(int signum)
{ //signal handler
  if (alarm_counter % 2 == 0){
    printf("Hello World!\n");
  } else {
    printf("Turing was right!\n");
  }
  alarm_counter++;
  alarm(1);
}

void intHandler(int signum)
{
  time_t end_time = time(NULL);
  double execution_time = difftime(end_time, begin_time);
  printf("Total alarms executed: %d\n", alarm_counter);
  printf("Toatl execution time: %.2lf seconds\n", execution_time);
  exit(0);
}
int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, intHandler);
  alarm(1); //Schedule a SIGALRM for 1 second
  begin_time = time(NULL);

  while (1)
  {
    //sleep(1); removed sleep for an infinite loop of "Turing was right" & "Hello World"
  }
  return 0; //never reached
}