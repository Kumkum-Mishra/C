#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // fork, exec, getpid
#include <sys/types.h>  // pid_t
#include <sys/wait.h>   // wait
#include <sys/stat.h>   // stat
#include <dirent.h>     // opendir, readdir, closedir

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("Child Process: PID = %d\n", getpid());

        execl("/bin/ls", "ls", NULL);

        perror("execl failed");
        exit(EXIT_FAILURE);
    } else {
        int status;
        wait(&status); 

        if (WIFEXITED(status)) {
            printf("Parent Process: Child exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Parent Process: Child did not terminate normally\n");
        }

        struct stat fileStat;
        if (stat(__FILE__, &fileStat) == 0) {
            printf("File Size: %ld bytes\n", fileStat.st_size);
        } else {
            perror("stat failed");
        }

        DIR *dir = opendir(".");
        if (dir != NULL) {
            struct dirent *entry;
            printf("Directory contents:\n");
            while ((entry = readdir(dir)) != NULL) {
                printf("%s\n", entry->d_name);
            }
            closedir(dir); 
        } else {
            perror("opendir failed");
        }
    }

    return 0;
}
