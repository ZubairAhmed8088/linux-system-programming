#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>

int main() {

    /* -------- FILE OPERATIONS -------- */

    // open(): create or open file x.txt
    int fd = open("x.txt", O_CREAT | O_RDWR, 0644);

    // write(): write "Hi" into file
    write(fd, "Hi", 2);

    // move file offset to beginning
    lseek(fd, 0, SEEK_SET);

    // read(): read data from file
    char file_buf[10];
    read(fd, file_buf, sizeof(file_buf));
    printf("File content: %s\n", file_buf);

    // close(): close file
    close(fd);


    /* -------- readlink() -------- */

    char link_buf[100];
    ssize_t len = readlink("/bin/sh", link_buf, sizeof(link_buf));
    link_buf[len] = '\0';
    printf("/bin/sh -> %s\n", link_buf);


    /* -------- SOCKET + IPC -------- */

    // socketpair(): create two connected sockets
    int sv[2];
    socketpair(AF_UNIX, SOCK_STREAM, 0, sv);


    /* -------- PROCESS -------- */

    pid_t pid = fork();

    if (pid == 0) {
        // Child process

        // recv(): receive data from parent
        char recv_buf[20];
        recv(sv[1], recv_buf, sizeof(recv_buf), 0);
        printf("Child received: %s\n", recv_buf);

        // exec(): replace child with echo command
        execl("/bin/echo", "echo", "Child executed exec()", NULL);

    } else {
        // Parent process

        // send(): send data to child
        send(sv[0], "Hello", 5, 0);
    }

    return 0;
}

/*
 SHORT NOTES:

 open()      -> creates or opens a file
 write()     -> writes data to file
 read()      -> reads data from file
 close()     -> closes file descriptor

 readlink()  -> reads target of a symbolic link

 socketpair()-> creates two connected sockets
 fork()      -> creates child process
 send()      -> sends data through socket
 recv()      -> receives data from socket
 exec()      -> replaces current process with new program
*/

