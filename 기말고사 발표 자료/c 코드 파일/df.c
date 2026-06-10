#include <stdio.h>
#include <sys/statvfs.h>

// df: statvfs()를 이용한 파일 시스템 총 블록 구조 및 잔여 남은 용량 계산
int main() {
    struct statvfs vfs;
    // 루트디렉토리(/)를 기준으로 탐색
    if (statvfs("/", &vfs) == 0) {
        long total_space = vfs.f_blocks * vfs.f_frsize;
        long free_space = vfs.f_bfree * vfs.f_frsize;
        long used_space = total_space - free_space;
        printf("File System Root (/) Disk Usage Info:\n");
        printf("Total Space: %ld MB\n", total_space / (1024 * 1024));
        printf("Used Space:  %ld MB\n", used_space / (1024 * 1024));
        printf("Free Space:  %ld MB\n", free_space / (1024 * 1024));
    } else {
        perror("df error");
        return 1;
    }
    return 0;
}