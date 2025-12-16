#include <stdio.h>    // printf()
#include <unistd.h>   // fork(), getpid()

int main() {

    /*
     fork():
     ------
     Creates a new process called child process.

     Syntax:
       pid_t fork(void);
    */

    /*
     fork() returns:
       0  -> child process
       >0 -> parent process (child PID)
       -1 -> failure
    */
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        /*
         Child process block.
        */
        printf("Child process running, PID = %d\n", getpid());
    } else {
        /*
         Parent process block.
        */
        printf("Parent process running, Child PID = %d\n", pid);
    }

    return 0;
}

/*
 SHORT NOTES:

 fork() creates a child process.
 Both parent and child run the same code.
*/

