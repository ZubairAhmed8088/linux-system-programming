/*
=================================================================
READLINK() SYSTEM CALL – FILE SYSTEM (LINUX)
=================================================================

THIS PROGRAM DEMONSTRATES:
1. What readlink() system call is
2. How to read the target of a symbolic link
3. How readlink() works with filesystem links
4. Why null termination is required manually
5. How symbolic links are resolved

DEFINITION:
readlink() is a Linux system call used to read the
target path of a symbolic link. It retrieves the
actual file or path that the symbolic link points to.

SYNTAX:
ssize_t readlink(const char *pathname, char *buffer, size_t bufsiz);

SYNTAX EXPLANATION:
ssize_t             -> Return type
                       Number of bytes placed in buffer
                       -1 on failure

readlink             -> System call name

const char *pathname -> Path of the symbolic link
                        whose target is to be read

char *buffer         -> Memory buffer where the target
                        path will be stored

size_t bufsiz        -> Size of the buffer

KEY POINTS:
- readlink() works only on symbolic links
- It does NOT add a null terminator
- Buffer must be manually null-terminated
- It does not follow the link, only reads it
- Returns number of bytes written to buffer

WHY readlink()?
- To find real target of symbolic links
- To inspect filesystem links
- To debug path redirections
- To analyze system binaries

IMPORTANT API:
readlink() -> Read symbolic link target

WHAT THIS PROGRAM DOES (STEP BY STEP):

STEP 1: Calls readlink() on a symbolic link
STEP 2: Stores the target path in buffer
STEP 3: Adds null terminator manually
STEP 4: Prints the resolved target path

EXPECTED OUTPUT (WHEN PROGRAM IS RUN):

1. Symbolic link target is read
2. Target path is printed
3. Program exits normally

=================================================================
*/

#include <stdio.h>    // For printf(), perror()
#include <unistd.h>   // For readlink()

/*
-----------------------------------------------------------------
MAIN FUNCTION
-----------------------------------------------------------------
This program demonstrates basic usage of readlink() system call.
*/
int main()
{
    char buffer[256];
    ssize_t len;

    /*
    STEP 1: Read symbolic link target
    ---------------------------------
    "/bin/sh" is commonly a symbolic link
    */
    len = readlink("/bin/sh", buffer, sizeof(buffer) - 1);

    if (len == -1)
    {
        perror("readlink failed");
        return 1;
    }

    /*
    STEP 2: Add null terminator
    ---------------------------
    readlink() does not add '\0'
    */
    buffer[len] = '\0';

    /*
    STEP 3: Print resolved path
    ---------------------------
    */
    printf("/bin/sh points to: %s\n", buffer);

    return 0;
}

/*
=================================================================
SHORT NOTES – QUICK REVISION
=================================================================

1. readlink() reads target of a symbolic link
2. Does not follow the link, only reads it
3. Does not append null terminator
4. Returns number of bytes read
5. Works only on symbolic links
6. Useful for filesystem inspection

DEFINITION (IN SIMPLE WORDS):
readlink() tells you where a symbolic
link is actually pointing.

REAL-TIME EXAMPLES:
- Checking /bin/sh implementation
- Debugging symlink issues
- Inspecting filesystem structure
- Analyzing system binaries

=================================================================
*/

