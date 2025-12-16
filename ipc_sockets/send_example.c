#include <stdio.h>      // printf()
#include <unistd.h>     // close()
#include <sys/socket.h> // socketpair(), send()

int main() {

    /*
     send():
     ------
     Used to send data through a socket.

     Syntax:
       ssize_t send(int sockfd, const void *buf, size_t len, int flags);
    */

    /*
     Create two connected sockets using socketpair().
    */
    int sv[2];
    socketpair(AF_UNIX, SOCK_STREAM, 0, sv);

    /*
     Send data from sv[0] to sv[1].
    */
    send(sv[0], "Hello", 5, 0);

    printf("Data sent through socket\n");

    /*
     Close both sockets.
    */
    close(sv[0]);
    close(sv[1]);

    return 0;
}

/*
 SHORT NOTES:

 send() sends data through a socket.
 Here "Hello" is sent from one socket to another.
*/

