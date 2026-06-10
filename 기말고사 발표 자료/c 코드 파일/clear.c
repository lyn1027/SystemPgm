#include <stdio.h>

// clear: ANSI 탈출 코드를 이용한 터미널 화면 초기화
int main() {
    // \033[H: 커서를 홈 위치로, \033[J: 화면 전체 지움
    printf("\033[H\033[J");
    return 0;
}