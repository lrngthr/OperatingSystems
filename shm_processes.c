#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void ParentProcess(int []);
void ChildProcess(int []);

int  main(int  argc, char *argv[])
{
     int    ShmID;
     int    *ShmPTR;
     pid_t  pid;
     int    status;

     if (argc != 1) {
          printf("Use: %s\n", argv[0]);
          exit(1);
     }

     ShmID = shmget(IPC_PRIVATE, 2 * sizeof(int), IPC_CREAT | 0666);
     if (ShmID < 0) {
          printf("*** shmget error (server) ***\n");
          exit(1);
     }
     printf("Server has received a shared memory for BankAccount and Turn...\n");

     ShmPTR = (int *) shmat(ShmID, NULL, 0);
     if (*ShmPTR == -1) {
          printf("*** shmat error (server) ***\n");
          exit(1);
     }
     printf("Server has attached the shared memory...\n");

     ShmPTR[0] = 0;  // Initialize BankAccount to 0
     ShmPTR[1] = 0;  // Initialize Turn to 0

     printf("Server is about to fork a child process...\n");
     pid = fork();
     if (pid < 0) {
          printf("*** fork error (server) ***\n");
          exit(1);
     }
     else if (pid == 0) {
          ChildProcess(ShmPTR);
          exit(0);
     }

     ParentProcess(ShmPTR);

     wait(&status);
     printf("Server has detected the completion of its child...\n");
     shmdt((void *) ShmPTR);
     printf("Server has detached its shared memory...\n");
     shmctl(ShmID, IPC_RMID, NULL);
     printf("Server has removed its shared memory...\n");
     printf("Server exits...\n");
     exit(0);
}

void ParentProcess(int  SharedMem[])
{
    srand(time(NULL));
    for (int i = 0; i < 25; i++) {
        sleep(rand() % 6);

        int account = SharedMem[0];
        while (SharedMem[1] != 0) {
            // Wait for the child's turn
        }

        if (account <= 100) {
            int balance = rand() % 101;
            if (balance % 2 == 0) {
                account += balance;
                printf("Dear old Dad: Deposits $%d / Balance = $%d\n", balance, account);
            } else {
                printf("Dear old Dad: Doesn't have any money to give\n");
            }
        } else {
            printf("Dear old Dad: Thinks Student has enough Cash ($%d)\n", account);
        }

        SharedMem[0] = account;
        SharedMem[1] = 1;
    }
}

void ChildProcess(int  SharedMem[])
{
    srand(time(NULL) ^ getpid());
    for (int i = 0; i < 25; i++) {
        sleep(rand() % 6);

        int account = SharedMem[0];
        while (SharedMem[1] != 1) {
            // Wait for the parent's turn
        }

        int balance = rand() % 51;
        printf("Poor Student needs $%d\n", balance);

        if (balance <= account) {
            account -= balance;
            printf("Poor Student: Withdraws $%d / Balance = $%d\n", balance, account);
        } else {
            printf("Poor Student: Not Enough Cash ($%d)\n", account);
        }

        SharedMem[0] = account;
        SharedMem[1] = 0;
    }
}
