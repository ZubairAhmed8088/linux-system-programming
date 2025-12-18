/*
=================================================================
CLOSE() SYSTEM CALL – FILE OPERATIONS (LINUX)
=================================================================

THIS PROGRAM DEMONSTRATES:
1. What close() system call is
2. Why closing a file descriptor is important
3. How close() releases system resources
4. What happens after a file descriptor is closed

DEFINITION:
close() is a Linux system call used to close an
open file descriptor and release all resources
associated with it.

SYNTAX:
int close(int fd);

SYNTAX EXPLANATION:
int            -> Return type
                  0 on success
                  -1 on failure

close          -> System call name

int fd         -> File descriptor that needs to be closed
                  (obtained from open(), socket(), etc.)

KEY POINTS:
- close() works on a valid file descriptor
- It releases kernel resources
- After close(), the file descriptor becomes invalid
- Using a closed descriptor causes errors
- Every open() must be paired with close()

WHY close()?
- To prevent file descriptor leaks
- To free system resources
- To ensure data is flushed properly
- To keep system stable

IMPORTANT API:
open()  -> Open file
close() -> Close file descriptor

WHAT THIS PROGRAM DOES (STEP BY STEP):

STEP 1: Opens a file using open()
STEP 2: Writes data into the file
STEP 3: Calls close() to close the file
STEP 4: Exits program cleanly

EXPECTED OUTPUT (WHEN PROGRAM IS RUN):

1. File is opened successfully
2. Data is written to file
3. File is closed successfully

=================================================================
*/

#include <stdio.h>    // For printf(), perror()
#include <fcntl.h>    // For open()
#include <unistd.h>   // For close(), write()

/*
-----------------------------------------------------------------
MAIN FUNCTION
-----------------------------------------------------------------
This program demonstrates basic usage of close() system call.
*/
int main()
{
    int fd;
    char message[] = "Testing close() system call\n";

    /*
    STEP 1: Open or create file
    ---------------------------
    */
    fd = open("x.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open failed");
        return 1;
    }

    /*
    STEP 2: Write data into file
    ----------------------------
    */
    write(fd, message, sizeof(message) - 1);

    /*
    STEP 3: Close file descriptor
    -----------------------------
    After this call, fd must not be used again.
    */
    if (close(fd) == -1)
    {
        perror("close failed");
        return 1;
    }

    printf("File closed successfully\n");

    return 0;
}

/*
=================================================================
SHORT NOTES – QUICK REVISION
=================================================================

1. close() releases file descriptor resources
2. Must be called after open()
3. Prevents file descriptor leaks
4. File descriptor becomes invalid after close()
5. Returns 0 on success
6. Works with files, pipes, sockets

DEFINITION (IN SIMPLE WORDS):
close() tells the operating system that the
program is done using the file or resource.

REAL-TIME EXAMPLES:
- Closing log files
- Closing socket connections
- Releasing device access
- Ending file operations properly

=================================================================
*/

