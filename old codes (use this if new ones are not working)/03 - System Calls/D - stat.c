#include <stdio.h>
#include <sys/stat.h>
int main()
{
    struct stat nfile;
    stat("hello.c", &nfile);
    printf("Size of file: %ld\n", nfile.st_size);
    printf("Last access time: %ld\n", nfile.st_atime);
    printf("Permission of file: %d\n", nfile.st_mode);
    printf("Last modified time: %ld\n", nfile.st_mtime);
    printf("UserID: %u\n", nfile.st_uid);
    printf("GroupID: %d\n", nfile.st_gid);
    printf("No. of Links: %ld\n", nfile.st_nlink);
    printf("Block size: %ld\n", nfile.st_blksize);
    return 0;
}
