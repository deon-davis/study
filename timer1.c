#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
void cbf(union sigval k)
{
 printf("\n cbf");
}

int main()
{
int arg = 0;
struct sigevent sev;
memset(&sev,0,sizeof(sev));
timer_t timer;
struct itimerspec its;
memset(&its,0,sizeof(its));
sev.sigev_notify = SIGEV_THREAD;
sev.sigev_notify_function = &cbf;
sev.sigev_value.sival_ptr = &arg;
if(timer_create(CLOCK_MONOTONIC, &sev, &timer)==0)
 printf("timer");

its.it_value.tv_sec = 4;
its.it_value.tv_nsec = 0;
its.it_interval.tv_sec = its.it_value.tv_sec;
its.it_interval.tv_nsec = its.it_value.tv_nsec;

timer_settime(timer, 0, &its, NULL);
sleep(20);
return(0);
}
