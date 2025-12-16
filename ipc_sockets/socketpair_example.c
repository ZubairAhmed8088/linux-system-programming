#include <stdio.h>      // printf()
#include <unistd.h>     // close()
#include <sys/socket.h> // socketpair()

int main() {

    /*
     socketpair():
     ------------
     Creates two connected sockets for communication.

     Syntax:
       int socketpair(int domain, int type, int protocol, int sv[2]);
    */

    /*
     sv[0] and sv[1] will be two connected sockets.
    */
    int sv[2];

    /*
     AF_UNIX     -> local communication
     SOCK_STREAM-> reliable, bidirectional communication
    */
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sv) == -1) {
        perror("socketpair failed");
        return 1;
    }

    printf("Socket pair created: sv[0]=%d, sv[1]=%d\n", sv[0], sv[1]);

    /*
     Close both sockets after use.
    */
    close(sv[0]);
    close(sv[1]);

    return 0;
}

/*
 SHORT NOTES:

 socketpair() creates two connected sockets.
 These sockets can communicate with each other.
*/

