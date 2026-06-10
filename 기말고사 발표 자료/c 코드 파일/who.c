#include <stdio.h>
#include <utmp.h>

// who: 시스템 로그 정보 탐색 및 로그인 세션 출력
int main() {
    struct utmp *u;
    
    // 엔트리의 처음으로 이동
    setutent();
    
    // 로그인된 사용자 프로세스만 필터링하여 출력
    while ((u = getutent())) {
        if (u->ut_type == USER_PROCESS) {
            printf("%s\t%s\t(%s)\n", u->ut_user, u->ut_line, u->ut_host);
        }
    }
    endutent();
    return 0;
}