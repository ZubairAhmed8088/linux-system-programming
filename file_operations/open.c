/*
=================================================================
OPEN() SYSTEM CALL – FILE OPERATIONS (LINUX)
=================================================================

THIS PROGRAM DEMONSTRATES:
1. What open() system call is
2. How to open an existing file
3. How to create a new file using open()
4. How file descriptors work
5. How open() is used in file operations

DEFINITION:
open() is a Linux system call used to open an existing
file or create a new file and return a file descriptor
that is used for further file operations.

SYNTAX:
int open(const char *pathname, int flags, mode_t mode);

SYNTAX EXPLANATION:
int              -> Return type of open()
                    Returns file descriptor on success,
                    returns -1 on failure

open             -> System call name

const char *pathname
                 -> Path or name of the file to be opened
                    or created

int flags        -> Specifies how the file should be opened
                    (read, write, create, append, etc.)

mode_t mode      -> Specifies file permissions
                    Used only when O_CREAT flag is set

KEY POINTS:
- open() is used for file access in Linux
- It returns an integer called file descriptor
- File descriptor is used by read(), write(), close()
- open() can create files using O_CREAT
- File permissions are set at creation time

WHY open()?
- To read data from files
- To write data into files
- To create files programmatically
- To access device files

IMPORTANT FLAGS:
O_RDONLY  -> Open file for read only
O_WRONLY  -> Open file for write only
O_RDWR    -> Open file for read and write
O_CREAT   -> Create file if it does not exist
O_APPEND  -> Append data at end of file
O_TRUNC   -> Truncate file

IMPORTANT API:
open()  -> Open or create file
close() -> Close file descriptor

WHAT THIS PROGRAM DOES (STEP BY STEP):

STEP 1: Calls open() to create or open a file
STEP 2: Receives file descriptor from open()
STEP 3: Checks if open() failed
STEP 4: Closes the file using close()

EXPECTED OUTPUT (WHEN PROGRAM IS RUN):

1. File is created if not present
2. Program prints file descriptor value
3. File is successfully opened and closed

=================================================================
*/

#include <stdio.h>    // For printf(), perror()
#include <fcntl.h>    // For open(), flags
#include <unistd.h>   // For close()

/*
-----------------------------------------------------------------
MAIN FUNCTION
-----------------------------------------------------------------
This program demonstrates basic usage of open() system call.
*/
int main()
{
    int fd;

    /*
    STEP 1: Open or Create File
    ---------------------------
    "x.txt"   -> File name
    O_CREAT   -> Create file if it does not exist
    O_RDWR    -> Open file for read and write
    0644      -> File permissions (rw-r--r--)
    */
    fd = open("x.txt", O_CREAT | O_RDWR, 0644);

    /*
    STEP 2: Check return value
    -------------------------
    fd >= 0  -> Success
    fd == -1 -> Failure
    */
    if (fd == -1)
    {
        perror("open failed");
        return 1;
    }

    printf("File opened successfully, fd = %d\n", fd);

    /*
    STEP 3: Close file
    -----------------
    Always close file descriptor after use
    */
    close(fd);

    return 0;
}

/*
=================================================================
SHORT NOTES – QUICK REVISION
=================================================================

1. open() is used to open or create files
2. open() returns a file descriptor
3. File descriptor is an integer reference to file
4. O_CREAT flag creates file if it does not exist
5. Permissions are applied only when file is created
6. open() must be followed by close()
7. Used with read(), write(), lseek()

DEFINITION (IN SIMPLE WORDS):
open() opens a file and gives a number that represents
the file inside the operating system.

REAL-TIME EXAMPLES:
- Opening log files
- Reading configuration files
- Writing output to files
- Accessing device files

=================================================================
*/

