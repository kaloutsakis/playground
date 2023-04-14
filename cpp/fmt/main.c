#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#include <linux/limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char** argv) {
    printf("Hello, world!\n");
    printf("executable = %s\n", argv[0]);

    char buf[PATH_MAX] = {'\0'};

    int n = readlink("/proc/self/exe", buf, sizeof(buf));

    printf("n = %d\n", n);
    printf("path = %s\n", buf);
 
    return 0;
}
