#include <stdio.h>
#include <time.h>

// date: time() 및 ctime() 활용 현재 시간 포맷팅 출력
int main() {
    time_t t = time(NULL);
    if (t != (time_t)-1) {
        printf("%s", ctime(&t));
    } else {
        perror("date error");
        return 1;
    }
    return 0;
}