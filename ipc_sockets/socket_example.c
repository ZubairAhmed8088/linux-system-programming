/*
=================================================================
SOCKET() SYSTEM CALL – SOCKET / IPC (LINUX)
=================================================================

THIS PROGRAM DEMONSTRATES:
1. What socket() system call is
2. How to create a socket
3. Meaning of domain, type, and protocol
4. How socket descriptor is used
5. How sockets enable inter-process communication

DEFINITION:
socket() is a Linux system call used to create an
endpoint for communication. It returns a socket
descriptor that is used for network or local IPC.

SYNTAX:
int socket(int domain, int type, int protocol);

SYNTAX EXPLANATION:
int               -> Return type
                     Returns socket file descriptor on success
                     Returns -1 on failure

socket            -> System call name

int domain        -> Communication domain
                     AF_INET  : IPv4 Internet sockets
                     AF_INET6 : IPv6 Internet sockets
                     AF_UNIX  : Local (same machine) sockets

int type          -> Communication type
                     SOCK_STREAM : TCP (reliable)
                     SOCK_DGRAM  : UDP (datagram)

int protocol      -> Protocol to use
                     0 lets OS choose default protocol

KEY POINTS:
- socket() creates a communication endpoint
- It returns a socket file descriptor
- Socket descriptor is used by send(), recv(), close()
- socket() alone does not establish a connection
- Used for network and local IPC

WHY socket()?
- Network communication
- Client-server applications
- Inter-process communication
- Data exchange between systems

IMPORTANT APIs:
socket() -> Create socket
bind()   -> Bind address to socket
listen() -> Listen for connections
accept() -> Accept client connection
connect()-> Connect to server
close()  -> Close socket

WHAT THIS PROGRAM DOES (STEP BY STEP):

STEP 1: Calls socket() to create a socket
STEP 2: Checks return value
STEP 3: Prints socket descriptor
STEP 4: Closes the socket

EXPECTED OUTPUT (WHEN PROGRAM IS RUN):

1. Socket is created successfully
2. Socket file descriptor is printed
3. Socket is closed

=================================================================
*/

#include <stdio.h>      // For printf(), perror()
#include <unistd.h>     // For close()
#include <sys/socket.h> // For socket()
#include <netinet/in.h> // For AF_INET

/*
-----------------------------------------------------------------
MAIN FUNCTION
-----------------------------------------------------------------
This program demonstrates basic usage of socket() system call.
*/
int main()
{
    int sockfd;

    /*
    STEP 1: Create socket
    ---------------------
    AF_INET      -> IPv4
    SOCK_STREAM -> TCP
    0            -> Default protocol
    */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /*
    STEP 2: Check return value
    --------------------------
    */
    if (sockfd == -1)
    {
        perror("socket failed");
        return 1;
    }

    printf("Socket created successfully, fd = %d\n", sockfd);

    /*
    STEP 3: Close socket
    --------------------
    */
    close(sockfd);

    return 0;
}

/*
=================================================================
SHORT NOTES – QUICK REVISION
=================================================================

1. socket() creates a communication endpoint
2. Returns a socket file descriptor
3. Domain defines address family
4. Type defines communication style
5. Protocol usually set to 0
6. Used for network and IPC
7. Must be closed using close()

DEFINITION (IN SIMPLE WORDS):
socket() creates a doorway through which
processes communicate with each other.

REAL-TIME EXAMPLES:
- Web servers and browsers
- Client-server applications
- Network services
- Local IPC using UNIX sockets

=================================================================
*/

