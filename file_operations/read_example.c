/*
=================================================================
READ() SYSTEM CALL – FILE OPERATIONS (LINUX)
=================================================================

THIS PROGRAM DEMONSTRATES:
1. What read() system call is
2. How to read data from a file
3. How file descriptor is used with read()
4. How data is stored in a buffer
5. How end-of-file (EOF) is handled

DEFINITION:
read() is a Linux system call used to read data
from an open file, device, pipe, or socket
into a user-provided buffer.

SYNTAX:
ssize_t read(int fd, void *buffer, size_t count);

SYNTAX EXPLANATION:
ssize_t          -> Return type
                     Number of bytes read on success
                     0 on end-of-file (EOF)
                     -1 on failure

read              -> System call name

int fd            -> File descriptor from which data
                     is read (returned by open())

void *buffer      -> Memory buffer where read data
                     will be stored

size_t count      -> Maximum number of bytes to read

KEY POINTS:
- read() works with a valid file descriptor
- Data is copied into a user buffer
- File offset moves automatically after read()
- read() does not add a null character
- Must add '\0' manually for strings

WHY read()?
- To read file contents
- To read input from devices
- To receive data from sockets
- To read data from pipes

IMPORTANT API:
open()  -> Open file
read()  -> Read data
close() -> Close file

WHAT THIS PROGRAM DOES (STEP BY STEP):

STEP 1: Opens a file using open()
STEP 2: Calls read() to read data into buffer
STEP 3: Adds null terminator
STEP 4: Prints the data
STEP 5: Closes the file

EXPECTED OUTPUT (WHEN PROGRAM IS RUN):

1. File content is read
2. Content is printed on terminal
3. Program exits normally

=================================================================
*/

#include <stdio.h>    // For printf(), perror()
#include <fcntl.h>    // For open()
#include <unistd.h>   // For read(), close()

/*
-----------------------------------------------------------------
MAIN FUNCTION
-----------------------------------------------------------------
This program demonstrates basic usage of read() system call.
*/
int main()
{
    int fd;
    char buffer[100];

    /*
    STEP 1: Open file in read-only mode
    ----------------------------------
    */
    fd = open("x.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open failed");
        return 1;
    }

    /*
    STEP 2: Read data from file
    ---------------------------
    */
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);

    if (bytes_read == -1)
    {
        perror("read failed");
        close(fd);
        return 1;
    }

    /*
    STEP 3: Add null terminator
    ---------------------------
    read() does not add '\0'
    */
    buffer[bytes_read] = '\0';

    /*
    STEP 4: Print data
    ------------------
    */
    printf("Data read from file:\n%s\n", buffer);

    /*
    STEP 5: Close file
    ------------------
    */
    close(fd);

    return 0;
}

/*
=================================================================
SHORT NOTES – QUICK REVISION
=================================================================

1. read() reads data from a file descriptor
2. Returns number of bytes read
3. Returns 0 when EOF is reached
4. Does not append null terminator
5. File offset advances automatically
6. Used with files, pipes, sockets

DEFINITION (IN SIMPLE WORDS):
read() copies data from a file into
a memory buffer for program use.

REAL-TIME EXAMPLES:
- Reading configuration files
- Reading logs
- Receiving socket data
- Reading input from devices

=================================================================
*/

