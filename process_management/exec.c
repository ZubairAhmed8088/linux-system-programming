/*
=================================================================
EXEC() SYSTEM CALL – PROCESS MANAGEMENT (LINUX)
=================================================================

THIS PROGRAM DEMONSTRATES:
1. What exec() system call is
2. How a process image is replaced
3. Difference between fork() and exec()
4. Why code after exec() usually does not run
5. How exec() is used to run a new program

DEFINITION:
exec() is a family of Linux system calls used to
replace the current running process with a new
program. After exec(), the old program no longer exists.

SYNTAX:
int execl(const char *path, const char *arg, ..., NULL);

SYNTAX EXPLANATION:
int                 -> Return type
                       Does not return on success
                       Returns -1 on failure

execl               -> One of the exec family calls
                       (exec with argument list)

const char *path    -> Absolute path of the executable
                       to be loaded

const char *arg     -> First argument (program name)
                       followed by program arguments

NULL                -> Marks end of argument list

KEY POINTS:
- exec() does NOT create a new process
- It replaces the current process image
- Process ID (PID) remains the same
- Code after exec() does not run on success
- Usually used after fork()

WHY exec()?
- To run a different program from a process
- Used by shells to execute commands
- To load new executables
- To change process functionality

IMPORTANT APIs (EXEC FAMILY):
execl()   -> Exec with argument list
execv()   -> Exec with argument array
execle()  -> Exec with environment
execvp()  -> Search executable in PATH
execve()  -> Low-level system call

WHAT THIS PROGRAM DOES (STEP BY STEP):

STEP 1: Prints a message before exec()
STEP 2: Calls execl() to execute /bin/ls
STEP 3: Current process is replaced
STEP 4: Code after exec() runs only if exec fails

EXPECTED OUTPUT (WHEN PROGRAM IS RUN):

1. Message before exec() is printed
2. Output of ls command is printed
3. Message after exec() is NOT printed

=================================================================
*/

#include <stdio.h>    // For printf(), perror()
#include <unistd.h>   // For execl()

/*
-----------------------------------------------------------------
MAIN FUNCTION
-----------------------------------------------------------------
This program demonstrates basic usage of exec() system call.
*/
int main()
{
    /*
    STEP 1: Print message before exec
    --------------------------------
    */
    printf("Before exec() call\n");

    /*
    STEP 2: Replace current process with /bin/ls
    --------------------------------------------
    */
    execl("/bin/ls", "ls", "-l", NULL);

    /*
    STEP 3: This code runs ONLY if exec() fails
    -------------------------------------------
    */
    perror("exec failed");

    return 0;
}

/*
=================================================================
SHORT NOTES – QUICK REVISION
=================================================================

1. exec() replaces the current process
2. No new process is created
3. PID remains the same after exec()
4. Code after exec() does not execute on success
5. exec() is usually called after fork()
6. exec() loads a new executable into memory

DEFINITION (IN SIMPLE WORDS):
exec() stops the current program and starts
a completely new program in its place.

REAL-TIME EXAMPLES:
- Shell executing commands
- Child process loading a new program
- Servers spawning worker programs
- Running external utilities

=================================================================
*/

