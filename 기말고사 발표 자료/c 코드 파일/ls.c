#include <stdio.h>
#include <dirent.h>

// ls: opendir(), readdir()을 이용한 디렉토리 항목 순회
int main() {
    DIR *d = opendir(".");
    struct dirent *dir;
    if (d != NULL) {
        while ((dir = readdir(d)) != NULL) {
            // 숨김 파일(.)을 제외하고 출력
            if (dir->d_name[0] != '.') {
                printf("%s\n", dir->d_name);
            }
        }
        closedir(d);
    } else {
        perror("ls error");
        return 1;
    }
    return 0;
}