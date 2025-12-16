#include <stdio.h>    // printf()
#include <fcntl.h>    // open()
#include <unistd.h>   // write(), close()

int main() {

    /*
     write():
     --------
     Used to write data to a file using a file descriptor.

     Syntax:
       ssize_t write(int fd, const void *buf, size_t count);
    */

    /*
     First open the file so we get a file descriptor.
     File is opened in write mode.
    */
    int fd = open("x.txt", O_CREAT | O_WRONLY, 0644);

    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    /*
     "Hi"      -> data to write
     2         -> number of bytes to write
     fd        -> file descriptor of x.txt
    */
    write(fd, "Hi", 2);

    /*
     After writing, close the file.
    */
    close(fd);

    return 0;
}

/*
 SHORT NOTES:

 write() writes data to a file using a file descriptor.
 Here "Hi" is written into x.txt and the file is closed.
*/

