#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>

// whoami: 현재 로그인한 사용자명 조회
int main() {
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    if (pw != NULL) {
        printf("%s\n", pw->pw_name);
    } else {
        perror("whoami error");
        return 1;
    }
    return 0;
}