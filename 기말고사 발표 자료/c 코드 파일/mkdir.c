#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

// mkdir: 지정한 이름으로 디렉토리 생성
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_name>\n", argv[0]);
        return 1;
    }
    if (mkdir(argv[1], 0755) == 0) {
        printf("Directory '%s' created successfully.\n", argv[1]);
    } else {
        perror("mkdir error");
        return 1;
    }
    return 0;
}