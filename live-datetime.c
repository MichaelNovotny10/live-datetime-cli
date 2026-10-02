// Copyright (c) 2026 Michael Novotny <michael@michaelnovotny.dev>
// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <time.h>

// #define USE_CUSTOM_TIMEDATE_FORMAT

#if !defined(__linux__)
    #error OS not supported.
#endif

void updateDateTime();
void printDateTime();
void waitUntilNextSecond();

struct tm tmTime;
const char *escSequenceCursorUp = "\033[1A";

int main(void) {
    printf("\n"); // to counter the escape sequence

    while (1) {
        printDateTime();
        waitUntilNextSecond();
    }

    return 0;
}

void updateDateTime() {
    time_t realTime = time(NULL);

    // time() returns -1 on failure
    if (realTime == -1) {
        return;
    }

    struct tm *temp;

    // localtime returns NULL on failure
    if ((temp = localtime(&realTime)) == NULL) {
        return;
    }
    tmTime = *temp;
}

void printDateTime() {
    updateDateTime();

#if defined(USE_CUSTOM_TIMEDATE_FORMAT) // DD/MM/YYYY hh:mm:ss
    printf("%s%02d/%02d/%04d %02d:%02d:%02d\n",
           escSequenceCursorUp,
           tmTime.tm_mday, tmTime.tm_mon + 1, tmTime.tm_year + 1900,
           tmTime.tm_hour, tmTime.tm_min, tmTime.tm_sec);

#else // asctime() format
    printf("%s%s", escSequenceCursorUp, asctime(&tmTime));
#endif

    fflush(stdout);
}

void waitUntilNextSecond() {
    struct timespec nextSecond;

    // clock_gettime() returns -1 on failure
    if (clock_gettime(CLOCK_REALTIME, &nextSecond) == -1) {
        return;
    }
    
    nextSecond.tv_sec  += 1;
    nextSecond.tv_nsec  = 0;
    
    clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &nextSecond, NULL);
}
