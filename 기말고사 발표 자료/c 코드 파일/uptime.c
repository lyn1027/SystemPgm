#include <stdio.h>
#include <sys/sysinfo.h>

// uptime: sysinfo() 구조체의 uptime 필드를 통한 가동 시간 포맷 변환
int main() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        long uptime_secs = info.uptime;
        long days = uptime_secs / 86400;
        long hours = (uptime_secs % 86400) / 3600;
        long mins = (uptime_secs % 3600) / 60;
        printf("System Uptime: %ld days, %ld hours, %ld minutes\n", days, hours, mins);
    } else {
        perror("sysinfo error");
        return 1;
    }
    return 0;
}