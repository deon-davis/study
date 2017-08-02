#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int sig_no)
{
  if(sig_no == SIGINT)
    printf("received SIGINT\n");
}

int main(void)
{

 if(signal(SIGINT, sig_handler) == SIG_ERR)
  printf("\n cant catch SIGINT\n");

  while(1);
   sleep(1);
 return 0;

}
