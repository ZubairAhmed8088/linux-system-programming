/*
=================================================================
RECV() SYSTEM CALL – SOCKET / IPC (LINUX)
=================================================================

THIS PROGRAM DEMONSTRATES:
1. What recv() system call is
2. How to receive data from a socket
3. How socket descriptor is used with recv()
4. Meaning of parameters in recv()
5. How data is received into a buffer

DEFINITION:
recv() is a Linux system call used to receive data
from a connected socket into a user-provided buffer.

SYNTAX:
ssize_t recv(int sockfd, void *buffer, size_t len, int flags);

SYNTAX EXPLANATION:
ssize_t             -> Return type
                       Number of bytes received on success
                       0 if connection is closed
                       -1 on failure

recv                -> System call name

int sockfd           -> Socket file descriptor
                        (returned by socket())

void *buffer         -> Memory buffer where received data
                        will be stored

size_t len           -> Maximum number of bytes to receive

int flags             -> Special options for receiving data
                        Usually set to 0

KEY POINTS:
- recv() works on a valid socket descriptor
- Data is copied into user buffer
- Returns 0 when peer closes connection
- Used mainly with TCP sockets
- recv() blocks until data is available (by default)

WHY recv()?
- To receive data over network
- To read messages from another process
- To implement client-server communication
- To handle incoming socket data

IMPORTANT APIs:
socket() -> Create socket
send()   -> Send data
recv()   -> Receive data
close()  -> Close socket

WHAT THIS PROGRAM DOES (STEP BY STEP):

STEP 1: Creates a pair of connected sockets
STEP 2: Sends data using send()
STEP 3: Receives data using recv()
STEP 4: Prints received data
STEP 5: Closes sockets

EXPECTED OUTPUT (WHEN PROGRAM IS RUN):

1. Data is received successfully
2. Received message is printed
3. Program exits normally

=================================================================
*/

#include <stdio.h>      // For printf(), perror()
#include <unistd.h>     // For close()
#include <sys/socket.h> // For socketpair(), send(), recv()

/*
-----------------------------------------------------------------
MAIN FUNCTION
-----------------------------------------------------------------
This program demonstrates basic usage of recv() system call.
*/
int main()
{
    int sv[2];
    char buffer[100];

    /*
    STEP 1: Create connected socket pair
    ------------------------------------
    */
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sv) == -1)
    {
        perror("socketpair failed");
        return 1;
    }

    /*
    STEP 2: Send data
    -----------------
    */
    send(sv[0], "Hello from recv()", 17, 0);

    /*
    STEP 3: Receive data
    --------------------
    */
    ssize_t bytes_received = recv(sv[1], buffer, sizeof(buffer) - 1, 0);

    if (bytes_received == -1)
    {
        perror("recv failed");
        return 1;
    }

    /*
    STEP 4: Add null terminator
    ---------------------------
    */
    buffer[bytes_received] = '\0';

    printf("Received data: %s\n", buffer);

    /*
    STEP 5: Close sockets
    ---------------------
    */
    close(sv[0]);
    close(sv[1]);

    return 0;
}

/*
=================================================================
SHORT NOTES – QUICK REVISION
=================================================================

1. recv() receives data from a socket
2. Returns number of bytes received
3. Returns 0 when peer closes connection
4. Blocks until data is available
5. Used with send() in socket communication
6. Works with TCP and UNIX sockets

DEFINITION (IN SIMPLE WORDS):
recv() pulls data from a socket
into a program’s memory buffer.

REAL-TIME EXAMPLES:
- Receiving server responses
- Reading client messages
- Network data handling
- IPC using sockets

=================================================================
*/

