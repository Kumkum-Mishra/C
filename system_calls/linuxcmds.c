#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    struct dirent **namelist;
    int n, i;
    char pathname[100];
    
    if (getcwd(pathname, sizeof(pathname)) == NULL) {
        perror("getcwd() error");
        return 1;
    }

    n = scandir(pathname, &namelist, NULL, alphasort);
    if (n < 0) {
        perror("scandir() error");
        return 1;
    } else {

        for (i = 0; i < n; i++) {
            printf("%s\n", namelist[i]->d_name);
            free(namelist[i]);  
        }
        free(namelist); 
    }

    return 0;
}
