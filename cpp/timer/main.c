#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include <unistd.h>
#include <linux/limits.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>

#define trace(fp, level, format, ...)                                                                                                                 \
    do                                                                                                                                                \
    {                                                                                                                                                 \
        typedef struct timespec timespec;                                                                                                             \
        enum                                                                                                                                          \
        {                                                                                                                                             \
            NS_PRECISION = 9                                                                                                                          \
        };                                                                                                                                            \
        timespec ts = {0};                                                                                                                            \
        char datetime[sizeof("YYYY_MM_DD HH:MM:SS")] = {'\0'};                                                                                        \
        char nanosecs[sizeof("NNNNNNNNN")] = {'\0'};                                                                                                  \
        timespec_get(&ts, TIME_UTC);                                                                                                                  \
        strftime(datetime, sizeof(datetime), "%F %T", localtime(&ts.tv_sec));                                                                         \
        sprintf(nanosecs, "%09lu", ts.tv_nsec);                                                                                                       \
        fprintf(fp, "%s.%.*s %s %s(%d) :: <%s> " format "\n", datetime, NS_PRECISION, nanosecs, PROC_NAME, __func__, __LINE__, level, ##__VA_ARGS__); \
        fflush(fp);                                                                                                                                   \
    } while (false)

static inline void tc_1(int argc, char *argv[]);
static inline void tc_2(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    if (true)
    {
        tc_1(argc, argv);
    }

    if (true)
    {
        tc_2(argc, argv);
    }

    return EXIT_SUCCESS;
}

void tc_1(int argc, char *argv[])
{
    // Ununsed variables
    (void)argc;
    (void)argv;

    // Local type aliases
    typedef struct timespec timespec;

    {
        enum constants
        {
            REPETITIONS = 100,
            TYPES_OF_CLOCK = 2,
            CLOCK_TYPE_TSG = 0,
            CLOCK_TYPE_CRT = 1,
            NS_PRECISION = 9
        };

        timespec results[TYPES_OF_CLOCK][REPETITIONS] = {0};

        for (uint8_t i = 0; i < REPETITIONS; ++i)
        {
            timespec_get(&results[CLOCK_TYPE_TSG][i], TIME_UTC);
            clock_gettime(CLOCK_REALTIME, &results[CLOCK_TYPE_CRT][i]);

            char date_time[sizeof("YYYY-MM-DD HH:MM:SS")] = {'\0'};
            char ns[sizeof("NNNNNNNNN")] = {'\0'};
            strftime(date_time, sizeof(date_time), "%F %T", localtime(&results[CLOCK_TYPE_TSG][i].tv_sec));
            sprintf(ns, "%09lu", results[CLOCK_TYPE_TSG][i].tv_nsec);

            fprintf(stdout, "%s.%.*s\n", date_time, NS_PRECISION, ns);
        }

        for (uint8_t i = 0; i < REPETITIONS; ++i)
        {
            for (uint8_t type = 0; type < TYPES_OF_CLOCK; ++type)
            {
                char date_time[sizeof("YYYY-MM-DD HH:MM:SS")] = {'\0'};
                char ns[sizeof("NNNNNNNNN")] = {'\0'};
                strftime(date_time, sizeof(date_time), "%F %T", localtime(&results[type][i].tv_sec));
                sprintf(ns, "%09lu", results[type][i].tv_nsec);

                fprintf(stdout, "[type=%u] %s.%.*s\t", type, date_time, NS_PRECISION, ns);
            }
            fprintf(stdout, "\n");
        }
    }
}

void tc_2(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    trace(stdout, "info", "Starting %s", __func__);
    FILE *log = fopen("timer.log", "a");
    trace(log, "info", "Compiled at %s", __TIMESTAMP__);
    fclose(log);
}