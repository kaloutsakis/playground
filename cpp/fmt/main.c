#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#include <unistd.h>
#include <linux/limits.h>
#include <sys/types.h>
#include <sys/stat.h>

// #define __USE_XOPEN2K8

void fmt();

int main(__attribute__((unused)) int argc, char **argv)
{
    printf("Hello, world!\n");

    fmt();
    printf("executable = %s\n", argv[0]);

    char buf[PATH_MAX] = {'\0'};

    int n = readlink("/proc/self/exe", buf, sizeof(buf));
    // char *dir = dirname(buf);

    printf("n    = %d\n", n);
    printf("path = %s\n", buf);

    // printf("dir  = %s\n", dir);

    if (__linux__)
    {
        printf("Running Linux\n");
    }

#ifdef __USE_XOPEN2K8
    printf("__USE_XOPEN2K8 is defined\n");
#endif

#ifdef __NAME__
    printf("Name = %s is defined\n", __NAME__);
#endif

    return 0;
}

void fmt()
{
#ifdef _POSIX_SOURCE
    printf("_POSIX_SOURCE defined\n");
#endif

#ifdef _POSIX_C_SOURCE
    printf("_POSIX_C_SOURCE defined: %jdL\n",
           (intmax_t)_POSIX_C_SOURCE);
#endif

#ifdef _ISOC99_SOURCE
    printf("_ISOC99_SOURCE defined\n");
#endif

#ifdef _ISOC11_SOURCE
    printf("_ISOC11_SOURCE defined\n");
#endif

#ifdef _XOPEN_SOURCE
    printf("_XOPEN_SOURCE defined: %d\n", _XOPEN_SOURCE);
#endif

#ifdef _XOPEN_SOURCE_EXTENDED
    printf("_XOPEN_SOURCE_EXTENDED defined\n");
#endif

#ifdef _LARGEFILE64_SOURCE
    printf("_LARGEFILE64_SOURCE defined\n");
#endif

#ifdef _FILE_OFFSET_BITS
    printf("_FILE_OFFSET_BITS defined: %d\n", _FILE_OFFSET_BITS);
#endif

#ifdef _BSD_SOURCE
    printf("_BSD_SOURCE defined\n");
#endif

#ifdef _SVID_SOURCE
    printf("_SVID_SOURCE defined\n");
#endif

#ifdef _DEFAULT_SOURCE
    printf("_DEFAULT_SOURCE defined\n");
#endif

#ifdef _ATFILE_SOURCE
    printf("_ATFILE_SOURCE defined\n");
#endif

#ifdef _GNU_SOURCE
    printf("_GNU_SOURCE defined\n");
#endif

#ifdef _REENTRANT
    printf("_REENTRANT defined\n");
#endif

#ifdef _THREAD_SAFE
    printf("_THREAD_SAFE defined\n");
#endif

#ifdef _FORTIFY_SOURCE
    printf("_FORTIFY_SOURCE defined\n");
#endif
}
