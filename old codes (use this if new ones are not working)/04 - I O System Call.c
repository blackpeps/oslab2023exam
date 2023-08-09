#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int fd;
    char buffer[80];
    char msg[50] = "hello, how are you";
    fd = open("a.txt", O_RDWR);
    printf("fd=%d\n", fd);
    if (fd != -1)
    {
        printf("a.txt is opened with read, write access\n");
        write(fd, msg, sizeof(msg));
        lseek(fd, 0, SEEK_SET);
        read(fd, buffer, sizeof(buffer));
        printf("\n%s was written to my file\n", buffer);
        close(fd);
    }
    return 0;
}