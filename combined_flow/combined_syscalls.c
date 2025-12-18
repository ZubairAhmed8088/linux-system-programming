/*
=================================================================
ALL-IN-ONE LINUX SYSTEM CALLS – FILE, PROCESS & IPC
=================================================================

THIS PROGRAM DEMONSTRATES:
1. File operations using open(), write(), read(), close()
2. Reading symbolic link using readlink()
3. Local IPC using socketpair()
4. Process creation using fork()
5. Inter-process communication using send() and recv()
6. Program replacement using exec()

DEFINITION:
This program demonstrates how core Linux system calls
work together in a single flow involving file handling,
process creation, inter-process communication, and
program execution.

SYNTAX (MAJOR CALLS USED):
open(), write(), read(), close()
readlink()
socketpair()
fork()
send(), recv()
exec()

KEY POINTS:
- open() creates or opens a file
- write() writes data into a file
- read() reads data from a file
- close() releases file descriptor
- readlink() reads symbolic link target
- socketpair() creates connected sockets
- fork() creates a child process
- send()/recv() exchange data between processes
- exec() replaces current process image

WHY THIS PROGRAM?
- To understand how system calls work together
- To see real process + IPC interaction
- To serve as a final revision program
- To connect theory with practical execution

IMPORTANT APIs USED:
open(), write(), read(), close()
readlink()
socketpair()
fork()
send(), recv()
execl()

WHAT THIS PROGRAM DOES (STEP BY STEP):

FILE OPERATIONS:
STEP 1: open() creates or opens x.txt
STEP 2: write() writes "Hi" into file
STEP 3: lseek() moves offset to beginning
STEP 4: read() reads data back
STEP 5: close() closes the file

FILESYSTEM:
STEP 6: readlink() reads target of /bin/sh

IPC SETUP:
STEP 7: socketpair() creates two connected sockets

PROCESS MANAGEMENT:
STEP 8: fork() creates child process

IPC COMMUNICATION:
STEP 9: Parent sends message using send()
STEP 10: Child receives message using recv()

PROCESS REPLACEMENT:
STEP 11: Child calls exec() to run /bin/echo

EXPECTED OUTPUT (WHEN PROGRAM IS RUN):

1. File content: Hi
2. /bin/sh -> actual shell path
3. Child received: Hello
4. Output from echo command

NOTE:
Order of some outputs may vary due to scheduling.

=================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

/*
-----------------------------------------------------------------
MAIN FUNCTION
-----------------------------------------------------------------
This program demonstrates multiple Linux system calls
working together in a single execution flow.
*/
int main()
{
    /* -------- FILE OPERATIONS -------- */

    int fd = open("x.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open failed");
        return 1;
    }

    write(fd, "Hi", 2);

    lseek(fd, 0, SEEK_SET);

    char file_buf[10];
    ssize_t r = read(fd, file_buf, sizeof(file_buf) - 1);
    if (r == -1)
    {
        perror("read failed");
        close(fd);
        return 1;
    }
    file_buf[r] = '\0';

    printf("File content: %s\n", file_buf);
    close(fd);


    /* -------- readlink() -------- */

    char link_buf[100];
    ssize_t len = readlink("/bin/sh", link_buf, sizeof(link_buf) - 1);
    if (len == -1)
    {
        perror("readlink failed");
        return 1;
    }
    link_buf[len] = '\0';

    printf("/bin/sh -> %s\n", link_buf);


    /* -------- SOCKET + IPC -------- */

    int sv[2];
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sv) == -1)
    {
        perror("socketpair failed");
        return 1;
    }


    /* -------- PROCESS -------- */

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        /* CHILD PROCESS */
        close(sv[0]);

        char recv_buf[20];
        ssize_t n = recv(sv[1], recv_buf, sizeof(recv_buf) - 1, 0);
        if (n == -1)
        {
            perror("recv failed");
            return 1;
        }
        recv_buf[n] = '\0';

        printf("Child received: %s\n", recv_buf);

        execl("/bin/echo", "echo", "Child executed exec()", NULL);
        perror("exec failed");
    }
    else
    {
        /* PARENT PROCESS */
        close(sv[1]);

        send(sv[0], "Hello", 5, 0);
        wait(NULL);
    }

    return 0;
}

/*
=================================================================
SHORT NOTES – QUICK REVISION
=================================================================

open()       -> creates or opens a file
write()      -> writes data to file
read()       -> reads data from file
close()      -> closes file descriptor

readlink()   -> reads symbolic link target

socketpair() -> creates two connected sockets
fork()       -> creates a child process
send()       -> sends data through socket
recv()       -> receives data from socket
exec()       -> replaces current process with new program

DEFINITION (IN SIMPLE WORDS):
This program shows how Linux system calls work
together to handle files, processes, and
communication between processes.

REAL-TIME EXAMPLES:
- Shell execution
- Parent-child IPC
- Daemons and services
- System utilities

=================================================================
*/

