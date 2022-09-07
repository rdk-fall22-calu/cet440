/*
 *  @author Robert Krency, kre1188@pennwest.edu
 *  @date 8/26/22
 * 
 *  time.c - Prints to console the current day and time, with an incrementing clock
 *  
 */

#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int main() {

    time_t epochSeconds; 
    struct tm *curTime;
    char buf[1024] = {0};

    // Hide the console cursor
    // https://stackoverflow.com/a/55313602
    printf("\e[?25l");

    time(&epochSeconds);
    curTime = localtime(&epochSeconds);
    
    // Print the date
    memset(buf, 0, 1024);
    strftime(buf, 1024, "\rToday is %A - %B %d, %Y. Current time is:", curTime );
    puts(buf);

    while(1){
        time(&epochSeconds);
        curTime = localtime(&epochSeconds);
            
        // Print the time
        fprintf(stdout,"\r%02d:%02d:%02d",curTime->tm_hour, curTime->tm_min, curTime->tm_sec);
        fflush(stdout);
        sleep(1);
    }

    // exit
    return 0;
}