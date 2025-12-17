/*
=================================================================
SOCKETPAIR() SYSTEM CALL – SOCKET / IPC (LINUX)
=================================================================

THIS PROGRAM DEMONSTRATES:
1. What socketpair() system call is
2. How to create two connected sockets
3. How socketpair() enables local IPC
4. How data is shared between two sockets
5. How socketpair() is used with send() and recv()

DEFINITION:
socketpair() is a Linux system call used to create
a pair of connected sockets. These sockets can be
used for bidirectional communication between
processes on the same machine.

SYNTAX:
int socketpair(int domain, int type, int protocol, int sv[2]);

SYNTAX EXPLANATION:
int                -> Return type
                      0 on success
                      -1 on failure

socketpair         -> System call name

int domain          -> Communication domain
                       AF_UNIX for local IPC

int type            -> Socket type
                       SOCK_STREAM for reliable communication
                       SOCK_DGRAM for datagram communication

int protocol        -> Protocol to use
                       Usually 0 (default)

int sv[2]           -> Array to store two socket descriptors
                       sv[0] and sv[1] are connected sockets

KEY POINTS:
- socketpair() creates two connected sockets
- Both sockets can send and receive data
- Used only for local (same machine) IPC
- No bind(), listen(), or connect() required
- Commonly used with fork()

WHY socketpair()?
- Fast local IPC
- Parent-child communication
- Simple bidirectional data exchange
- Testing socket-based code

IMPORTANT APIs:
socketpair() -> Create connected sockets
send()       -> Send data
recv()       -> Receive data
close()      -> Close socket

WHAT THIS PROGRAM DOES (STEP BY STEP):

STEP 1: Creates a pair of connected sockets
STEP 2: Sends data through one socket
STEP 3: Receives data from the other socket
STEP 4: Prints received data
STEP 5: Closes both sockets

EXPECTED OUTPUT (WHEN PROGRAM IS RUN):

1. Data is sent successfully
2. Data is received successfully
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
This program demonstrates basic usage of socketpair() system call.
*/
int main()
{
    int sv[2];
    char buffer[100];

    /*
    STEP 1: Create socket pair
    --------------------------
    AF_UNIX      -> Local communication
    SOCK_STREAM -> Reliable, bidirectional
    */
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sv) == -1)
    {
        perror("socketpair failed");
        return 1;
    }

    /*
    STEP 2: Send data through first socket
    --------------------------------------
    */
    send(sv[0], "Hello from socketpair()", 22, 0);

    /*
    STEP 3: Receive data from second socket
    ---------------------------------------
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
    STEP 5: Close both sockets
    --------------------------
    */
    close(sv[0]);
    close(sv[1]);

    return 0;
}

/*
=================================================================
SHORT NOTES – QUICK REVISION
=================================================================

1. socketpair() creates two connected sockets
2. Used only for local IPC (AF_UNIX)
3. Both sockets are bidirectional
4. No need for bind(), listen(), connect()
5. Commonly used with fork()
6. Faster than network sockets for IPC

DEFINITION (IN SIMPLE WORDS):
socketpair() creates two sockets that are
directly connected to each other for
communication within the same system.

REAL-TIME EXAMPLES:
- Parent-child communication
- IPC in daemon processes
- Testing socket-based programs
- Internal communication in system services

=================================================================
*/

