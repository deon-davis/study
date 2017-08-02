#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void sig_handler(int signo)
{
 if(signo == SIGUSR1)
  printf("receive SIGUSR1\n");
 else if (signo == SIGKILL)
  printf("received SIGKILL\n");
 else if (signo == SIGSTOP)
  printf("received SIGSTOP\n");
}


int main(void)
{

 if(signal(SIGUSR1, sig_handler) == SIG_ERR)
   printf("\n cant catch SIGUSR1\n");
 if(signal(SIGKILL, sig_handler) == SIG_ERR)
   printf("\n cant catch SIGUSR1\n");
 if(signal(SIGSTOP, sig_handler) == SIG_ERR)
   printf("\n cant catch SIGUSR1\n");

 while(1)
   sleep(1);
 return 0;
}



