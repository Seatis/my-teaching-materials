#include <stdio.h>
#include <time.h>

void time_diff(struct tm t1, struct tm t2, struct tm *diff);

struct tm start(time_t raw_tm);
struct tm stop(time_t raw_tm);

//TODO: write a stopwatch program. If you hit enter start the stopwatch, if you hit enter again stop the watch. If you hit escape, the program should exit.
//use the time.h header: https://www.tutorialspoint.com/c_standard_library/c_function_localtime.htm
//it's enough if you can measure the elapsed seconds, and minutes

int main()
{
    struct tm start_time, stop_time, diff;
	time_t raw_time;

    int c;
    char state = 0;

    do {
        c = getch();
        if (c == 13 && state == 0) {
            start_time = start(raw_time);
            printf("Stopwatch started.\n");
            state = 1;
        }
        else if (c == 13 && state == 1) {
            stop_time = stop(raw_time);
            printf("Stopwatch stopped.\n");
            state = 0;
        }
        if (state == 0 && c != 27) {
            time_diff(start_time, stop_time, &diff);
            printf("Elapsed time is: %d minutes %d seconds.\n", 59-diff.tm_min, 60-diff.tm_sec);
        }
    } while(c != 27);

    return 0;
}

struct tm start(time_t raw_tm)
{
    struct tm start_time;
    raw_tm = time(NULL);
	start_time = *localtime(&raw_tm);
	return start_time;
}

struct tm stop(time_t raw_tm)
{
    struct tm stop_time;
    raw_tm = time(NULL);
	stop_time = *localtime(&raw_tm);
	return stop_time;
}

void time_diff(struct tm start, struct tm stop, struct tm *diff)
{
    if(stop.tm_sec > start.tm_sec){
        --start.tm_min;
        start.tm_sec += 60;
    }
    diff->tm_sec = start.tm_sec - stop.tm_sec;

    if(stop.tm_min > start.tm_min){
        --start.tm_hour;
        start.tm_min += 60;
    }
    diff->tm_min = start.tm_min - stop.tm_min;
}