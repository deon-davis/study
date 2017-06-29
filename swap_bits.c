#include<stdio.h>
#include<stdlib.h>

int main()
{
int num=(1<<2);
int temp;
int print = num;
printf("number \n");
while(print)
{
 printf(" %d",(print&1));
 print>>=1;
}
temp = ( (num>>3)&(1) ^ (num>>2)&(1));
num = num^(temp<<3);
num = num^(temp<<2);
print = num;
printf("\nbit swapped number\n");
while(print)
{
 printf(" %d",(print&1));
 print>>=1;
}
return 0;
}



