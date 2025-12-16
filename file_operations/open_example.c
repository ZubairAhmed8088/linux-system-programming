#include <stdio.h>    // printf()
#include <fcntl.h>    // open(), O_CREAT, O_RDWR
#include <unistd.h>   // close()

int main() {

    /*
     open():
     -------
     Used to open an existing file or create a new file.

     Syntax:
       int open(const char *pathname, int flags, mode_t mode);
    */

    /*
     Here:
       "x.txt"   -> file name
       O_CREAT  -> create file if it does not exist
       O_RDWR   -> open file for read and write
       0644     -> permissions: rw-r--r--
    */

    int fd = open("x.txt", O_CREAT | O_RDWR, 0644);

    /*
     Return value:
       fd >= 0  -> success (file descriptor)
       fd == -1 -> failure
    */
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    printf("x.txt created/opened successfully, fd = %d\n", fd);

    /*
     close():
     Always close the file after use
    */
    close(fd);

    return 0;
}

/*
 SHORT NOTES:

 open() creates or opens a file and returns a file descriptor.
 Here x.txt is created using O_CREAT | O_RDWR and closed after use.
*/

