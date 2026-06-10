#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// chown: 파일 소유자 및 그룹 ID 변경
int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <uid> <gid> <file_name>\n", argv[0]);
        return 1;
    }
    uid_t uid = atoi(argv[1]);
    gid_t gid = atoi(argv[2]);

    if (chown(argv[3], uid, gid) == 0) {
        printf("Owner of '%s' changed to UID:%d, GID:%d.\n", argv[3], uid, gid);
    } else {
        perror("chown error");
        return 1;
    }
    return 0;
}