#include <stdio.h>      // printf()
#include <unistd.h>     // close()
#include <sys/socket.h> // socket()
#include <netinet/in.h> // AF_INET

int main() {

    /*
     socket():
     --------
     Used to create a communication endpoint (socket).

     Syntax:
       int socket(int domain, int type, int protocol);
    */

    /*
     AF_INET      -> IPv4 Internet protocol
     SOCK_STREAM -> TCP (reliable, connection-oriented)
     0            -> default protocol
    */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /*
     socket() returns:
       >= 0 -> success (socket file descriptor)
       -1   -> failure
    */
    if (sockfd == -1) {
        perror("socket failed");
        return 1;
    }

    printf("Socket created successfully, fd = %d\n", sockfd);

    /*
     Close the socket after use.
    */
    close(sockfd);

    return 0;
}

/*
 SHORT NOTES:

 socket() creates a communication endpoint and returns a socket descriptor.
 Here a TCP IPv4 socket is created and then closed.
*/

