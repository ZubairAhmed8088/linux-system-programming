/*
=================================================================
FORK() SYSTEM CALL – PROCESS MANAGEMENT (LINUX)
=================================================================

THIS PROGRAM DEMONSTRATES:
1. What fork() system call is
2. How a new process (child) is created
3. Difference between parent and child process
4. How fork() return value is used
5. How both processes execute the same code

DEFINITION:
fork() is a Linux system call used to create a new
process by duplicating the calling process.
The new process is called the child process.

SYNTAX:
pid_t fork(void);

SYNTAX EXPLANATION:
pid_t          -> Return type (process ID type)
                  0   in child process
                  >0  in parent process (child PID)
                  -1  on failure

fork           -> System call name

void           -> fork() takes no arguments

KEY POINTS:
- fork() creates a child process
- Parent and child run the same program
- Memory is logically copied (copy-on-write)
- fork() returns different values in parent and child
- Parent and child run independently

WHY fork()?
- To perform multitasking
- To create parallel execution
- To handle multiple clients
- To create a child before exec()

IMPORTANT API:
fork()   -> Create a new process
getpid() -> Get process ID
getppid()-> Get parent process ID

WHAT THIS PROGRAM DOES (STEP BY STEP):

STEP 1: Calls fork() to create a child process
STEP 2: Checks return value of fork()
STEP 3: Child prints its PID and parent PID
STEP 4: Parent prints its PID and child PID

EXPECTED OUTPUT (WHEN PROGRAM IS RUN):

1. Parent process message is printed
2. Child process message is printed
3. Order may vary (scheduler dependent)

=================================================================
*/

#include <stdio.h>    // For printf(), perror()
#include <unistd.h>   // For fork(), getpid(), getppid()

/*
-----------------------------------------------------------------
MAIN FUNCTION
-----------------------------------------------------------------
This program demonstrates basic usage of fork() system call.
*/
int main()
{
    pid_t pid;

    /*
    STEP 1: Create a new process
    ----------------------------
    */
    pid = fork();

    /*
    STEP 2: Check fork() return value
    --------------------------------
    */
    if (pid == -1)
    {
        perror("fork failed");
        return 1;
    }

    /*
    CHILD PROCESS
    -------------
    fork() returns 0 in child
    */
    if (pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
    }

    /*
    PARENT PROCESS
    --------------
    fork() returns child PID in parent
    */
    else
    {
        printf("Parent Process\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);
    }

    return 0;
}

/*
=================================================================
SHORT NOTES – QUICK REVISION
=================================================================

1. fork() creates a child process
2. Parent and child run the same code
3. fork() returns 0 in child
4. fork() returns child PID in parent
5. fork() returns -1 on failure
6. Uses copy-on-write memory
7. Commonly followed by exec()

DEFINITION (IN SIMPLE WORDS):
fork() makes a copy of the running program
and starts it as a new process.

REAL-TIME EXAMPLES:
- Shell creating new commands
- Servers handling multiple clients
- Background process creation
- Process pipelines

=================================================================
*/

