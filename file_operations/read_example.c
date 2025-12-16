#include <stdio.h>    // printf()
#include <fcntl.h>    // open()
#include <unistd.h>   // read(), close()

int main() {

    /*
     read():
     -------
     Used to read data from a file using a file descriptor.

     Syntax:
       ssize_t read(int fd, void *buf, size_t count);
    */

    /*
     Open the file in read mode to get file descriptor.
    */
    int fd = open("x.txt", O_RDONLY);

    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    /*
     Buffer to store data read from file.
    */
    char buf[10];

    /*
     Read up to 10 bytes from x.txt into buf.
    */
    read(fd, buf, sizeof(buf));

    /*
     Print the data read from the file.
    */
    printf("Data read from file: %s\n", buf);

    /*
     Close the file after reading.
    */
    close(fd);

    return 0;
}

/*
 SHORT NOTES:

 read() reads data from a file into a buffer.
 Here data from x.txt is read and printed.
*/

