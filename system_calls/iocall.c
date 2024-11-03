#include <fcntl.h> 
#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 

int main(void) 
{ 
    int fd[2]; 
    char buf1[12] = "hello world"; 
    char buf2[12]; 
    ssize_t bytes_read; 
  
    fd[0] = open("foobar.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);  // Open the file named as "foobar.txt" 
    if (fd[0] < 0) {
        perror("Error opening file for writing");
        return 1;
    }

    if (write(fd[0], buf1, strlen(buf1)) < 0) {
        perror("Error writing to file");
        close(fd[0]);
        return 1;
    }

    if (lseek(fd[0], 0, SEEK_SET) < 0) {
        perror("Error seeking in file");
        close(fd[0]);
        return 1;
    }

    bytes_read = read(fd[0], buf2, sizeof(buf2) - 1); 
    if (bytes_read < 0) {
        perror("Error reading from file");
        close(fd[0]);
        return 1;
    }

    buf2[bytes_read] = '\0';

    if (write(STDOUT_FILENO, buf2, bytes_read) < 0) {
        perror("Error writing to stdout");
        close(fd[0]);
        return 1;
    }

    close(fd[0]); 
  
    return 0; 
}