#include <stdio.h>
#include <dirent.h>
#include <ctype.h>

// ps: /proc 가상 파일 시스템 내부의 PID 디렉토리 순회 검색 검색
int main() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    if (!dir) { perror("proc open error"); return 1; }

    printf("Active System PIDs running:\n");
    while ((entry = readdir(dir)) != NULL) {
        // 디렉토리 이름이 모두 숫자인 것(PID)들만 식별하여 추출
        if (isdigit(entry->d_name[0])) {
            printf("[%s] ", entry->d_name);
        }
    }
    printf("\n");
    closedir(dir);
    return 0;
}