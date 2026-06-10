#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

// stat: struct stat 구조체 기반 파일 메타데이터(크기, Inode) 파싱
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }
    struct stat file_stat;
    if (stat(argv[1], &file_stat) == 0) {
        printf("File: %s\n", argv[1]);
        printf("Size: %ld bytes\n", file_stat.st_size);
        printf("Inode: %ld\n", file_stat.st_ino);
        printf("Links: %ld\n", file_stat.st_nlink);
    } else {
        perror("stat error");
        return 1;
    }
    return 0;
}