#include <stdio.h>    // printf()
#include <fcntl.h>    // open()
#include <unistd.h>   // close(), write()

int main() {

    /*
     close():
     --------
     Used to close an open file descriptor and release resources.

     Syntax:
       int close(int fd);
    */

    /*
     Open a file to get a file descriptor.
    */
    int fd = open("x.txt", O_CREAT | O_WRONLY, 0644);

    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    /*
     Write some data to the file.
    */
    write(fd, "Bye", 3);

    /*
     close() releases the file descriptor.
     After close(), fd should not be used.
    */
    close(fd);

    printf("File closed successfully\n");

    return 0;
}

/*
 SHORT NOTES:

 close() closes an open file descriptor and frees resources.
 After closing, the file descriptor must not be used.
*/

