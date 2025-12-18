/*
=================================================================
WRITE() SYSTEM CALL – FILE OPERATIONS (LINUX)
=================================================================

THIS PROGRAM DEMONSTRATES:
1. What write() system call is
2. How to write data into a file
3. How file descriptor is used with write()
4. How many bytes are written
5. How file offset moves after write()

DEFINITION:
write() is a Linux system call used to write data
from a user-provided buffer into an open file,
device, pipe, or socket.

SYNTAX:
ssize_t write(int fd, const void *buffer, size_t count);

SYNTAX EXPLANATION:
ssize_t            -> Return type
                      Number of bytes written on success
                      -1 on failure

write              -> System call name

int fd              -> File descriptor to which data
                       will be written (from open())

const void *buffer  -> Memory buffer containing data
                       to be written

size_t count        -> Number of bytes to write from buffer

KEY POINTS:
- write() works with a valid file descriptor
- Data is written from buffer to file
- File offset moves forward after write()
- write() does not add any extra characters
- Partial writes are possible

WHY write()?
- To store data into files
- To write logs
- To send data through sockets
- To output data to devices

IMPORTANT API:
open()  -> Open file
write() -> Write data
close() -> Close file

WHAT THIS PROGRAM DOES (STEP BY STEP):

STEP 1: Opens a file using open()
STEP 2: Calls write() to write data into file
STEP 3: Prints number of bytes written
STEP 4: Closes the file

EXPECTED OUTPUT (WHEN PROGRAM IS RUN):

1. File is created (if not present)
2. Data is written into the file
3. Program exits normally

=================================================================
*/

#include <stdio.h>    // For printf(), perror()
#include <fcntl.h>    // For open()
#include <unistd.h>   // For write(), close()
#include <string.h>   // For strlen()

/*
-----------------------------------------------------------------
MAIN FUNCTION
-----------------------------------------------------------------
This program demonstrates basic usage of write() system call.
*/
int main()
{
    int fd;
    char message[] = "Hello from write() system call\n";

    /*
    STEP 1: Open or create file
    ---------------------------
    O_CREAT  -> Create file if it does not exist
    O_WRONLY -> Open file for write only
    O_TRUNC  -> Clear file content if it exists
    */
    fd = open("x.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open failed");
        return 1;
    }

    /*
    STEP 2: Write data to file
    --------------------------
    */
    ssize_t bytes_written = write(fd, message, strlen(message));

    if (bytes_written == -1)
    {
        perror("write failed");
        close(fd);
        return 1;
    }

    /*
    STEP 3: Print result
    -------------------
    */
    printf("Number of bytes written: %ld\n", bytes_written);

    /*
    STEP 4: Close file
    ------------------
    */
    close(fd);

    return 0;
}

/*
=================================================================
SHORT NOTES – QUICK REVISION
=================================================================

1. write() writes data to a file descriptor
2. Returns number of bytes written
3. File offset advances after write()
4. Does not add null terminator automatically
5. Works with files, pipes, sockets
6. Must handle partial writes

DEFINITION (IN SIMPLE WORDS):
write() sends data from memory into a file
or output destination.

REAL-TIME EXAMPLES:
- Writing logs
- Saving program output
- Sending socket messages
- Writing to device files

=================================================================
*/

