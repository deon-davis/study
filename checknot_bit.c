#include<stdio.h>
#include<stdlib.h>
#define mysizeof(x) ((char*)(&x+1)-(char*)&x)

int count_set_bit(int num) /*count the number of bit set in a number*/
{
 int count = 0;
 while(num > 0)
 {
  num = num & (num-1);
  count++;
 }
 return count;
}

int swap_oddeven_bits(int num) /*swap odd and even bits of 32 bit number*/
{
 int odd,even;
 odd = num & 0xAAAAAAAA; /* clears all the even bit to get odd bits*/
 even = num & 0x55555555; /* clears all the odd bit to get even bits*/
 odd >>= 1; 
 even <<=1;
 num = odd | even;
 return num;
}

int main()
{
int a,b,result;
result=mysizeof(a);  /*call sizeof implimentation*/ 
printf("\n%d",result);
result = 0;
printf("\nenter the number:");
scanf("%d",&b);
result = count_set_bit(b);
printf("the number of bit set:%d\n",result);
printf("enter number to swap bytes:");
scanf("%d",&b);
result = swap_oddeven_bits(b);
printf("swapped number: %d\n",result);
return 1;
}




