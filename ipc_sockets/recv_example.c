#include <stdio.h>      // printf()
#include <unistd.h>     // close()
#include <sys/socket.h> // socketpair(), recv(), send()

int main() {

    /*
     recv():
     ------
     Used to receive data from a socket.

     Syntax:
       ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    */

    /*
     Create two connected sockets using socketpair().
    */
    int sv[2];
    socketpair(AF_UNIX, SOCK_STREAM, 0, sv);

    /*
     Send data from one socket.
    */
    send(sv[0], "Hello", 5, 0);

    /*
     Buffer to receive data.
    */
    char buf[10];

    /*
     Receive data into buffer.
    */
    recv(sv[1], buf, sizeof(buf), 0);

    printf("Data received: %s\n", buf);

    /*
     Close both sockets.
    */
    close(sv[0]);
    close(sv[1]);

    return 0;
}

/*
 SHORT NOTES:

 recv() receives data from a socket.
 Here data sent through a socket is received and printed.
*/

