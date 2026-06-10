#include <stdio.h>
#include <sys/utsname.h>

// uname: struct utsname 구조체를 채우는 uname() 커널 구조 정보 호출
int main() {
    struct utsname system_info;
    if (uname(&system_info) == 0) {
        printf("System OS Name: %s\n", system_info.sysname);
        printf("Node (Host) Name: %s\n", system_info.nodename);
        printf("Kernel Release: %s\n", system_info.release);
        printf("Architecture:   %s\n", system_info.machine);
    } else {
        perror("uname error");
        return 1;
    }
    return 0;
}