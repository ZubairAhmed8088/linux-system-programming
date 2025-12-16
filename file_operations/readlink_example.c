#include <stdio.h>    // printf()
#include <unistd.h>   // readlink()

int main() {

    /*
     readlink():
     ----------
     Reads the target path of a symbolic link.

     Syntax:
       ssize_t readlink(const char *path, char *buf, size_t size);
    */

    /*
     Buffer to store the actual path.
    */
    char buf[100];

    /*
     "/bin/sh" is a symbolic link.
     readlink() gets the real file it points to.
    */
    ssize_t len = readlink("/bin/sh", buf, sizeof(buf));

    if (len == -1) {
        perror("readlink failed");
        return 1;
    }

    /*
     readlink() does not add null character,
     so we add it manually.
    */
    buf[len] = '\0';

    printf("/bin/sh points to: %s\n", buf);

    return 0;
}

/*
 SHORT NOTES:

 readlink() reads the target of a symbolic link.
 Here it prints the real path of /bin/sh.
*/

