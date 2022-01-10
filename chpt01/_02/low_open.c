#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
void error_handling(char *message);

int main(void){
    int fd;
    char buf[] = "Let's go!\n";

    fd = open("data.txt", O_CREAT|O_WRONLY|O_TRUNC);
    if( fd==-1)
        error_handling("open() error!");
    printf("file descriptor: %d \n", fd);

    int writen_byte = write(fd, buf, sizeof(buf));
    if( writen_byte==-1)
        error_handling("write() error!");
    
    printf("writen byte is %d\n", writen_byte);
    
    close(fd);
    return 0;
}
void error_handling(char *message){
    fputs(message, stderr);
    fputc('\n',stderr);
    exit(1);
}