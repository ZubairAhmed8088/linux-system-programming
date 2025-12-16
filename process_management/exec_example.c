#include <stdio.h>    // printf()
#include <unistd.h>   // execl()

int main() {

    /*
     exec():
     ------
     Replaces the current process with a new program.

     Syntax:
       int execl(const char *path, const char *arg, ..., NULL);
    */

    printf("Before exec()\n");

    /*
     This will replace the current process
     with the /bin/echo program.
    */
    execl("/bin/echo", "echo", "Hello from exec()", NULL);

    /*
     This line executes only if exec() fails.
    */
    perror("exec failed");

    return 0;
}

/*
 SHORT NOTES:

 exec() replaces the current process with a new program.
 Code after exec() does not run if exec() succeeds.
*/

