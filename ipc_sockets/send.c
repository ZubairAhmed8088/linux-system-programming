/*
=================================================================
SEND() SYSTEM CALL – SOCKET / IPC (LINUX)
=================================================================

THIS PROGRAM DEMONSTRATES:
1. What send() system call is
2. How to send data through a socket
3. How socket descriptor is used with send()
4. Meaning of parameters in send()
5. How data is transmitted between processes

DEFINITION:
send() is a Linux system call used to send data
from a user-provided buffer through a connected
socket to another process or system.

SYNTAX:
ssize_t send(int sockfd, const void *buffer, size_t len, int flags);

SYNTAX EXPLANATION:
ssize_t             -> Return type
                       Number of bytes sent on success
                       -1 on failure

send                -> System call name

int sockfd           -> Socket file descriptor
                        (returned by socket())

const void *buffer   -> Memory buffer containing data
                        to be sent

size_t len           -> Number of bytes to send
                        from the buffer

int flags             -> Special options for sending data
                        Usually set to 0

KEY POINTS:
- send() works on a valid socket descriptor
- Data is sent from buffer to socket
- Used mainly with connected sockets (TCP)
- Returns number of bytes actually sent
- Partial sends are possible

WHY send()?
- To transmit data over network
- To communicate between processes
- To send messages in client-server programs
- To exchange data using sockets

IMPORTANT APIs:
socket() -> Create socket
send()   -> Send data
recv()   -> Receive data
close()  -> Close socket

WHAT THIS PROGRAM DOES (STEP BY STEP):

STEP 1: Creates a pair of connected sockets
STEP 2: Calls send() to send data through socket
STEP 3: Prints confirmation message
STEP 4: Closes sockets

EXPECTED OUTPUT (WHEN PROGRAM IS RUN):

1. Data is sent successfully
2. Confirmation message is printed
3. Program exits normally

=================================================================
*/

#include <stdio.h>      // For printf(), perror()
#include <unistd.h>     // For close()
#include <sys/socket.h> // For socketpair(), send()

/*
-----------------------------------------------------------------
MAIN FUNCTION
-----------------------------------------------------------------
This program demonstrates basic usage of send() system call.
*/
int main()
{
    int sv[2];

    /*
    STEP 1: Create connected socket pair
    ------------------------------------
    AF_UNIX      -> Local communication
    SOCK_STREAM -> Reliable connection
    */
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sv) == -1)
    {
        perror("socketpair failed");
        return 1;
    }

    /*
    STEP 2: Send data through socket
    --------------------------------
    */
    if (send(sv[0], "Hello from send()", 17, 0) == -1)
    {
        perror("send failed");
        return 1;
    }

    printf("Data sent successfully\n");

    /*
    STEP 3: Close sockets
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

1. send() sends data through a socket
2. Works with socket file descriptors
3. Returns number of bytes sent
4. May send fewer bytes than requested
5. Commonly used with TCP sockets
6. Used with recv() on receiving side

DEFINITION (IN SIMPLE WORDS):
send() pushes data from a program
through a socket to another program.

REAL-TIME EXAMPLES:
- Sending data to a server
- Client-server messaging
- Network communication
- IPC using sockets

=================================================================
*/

