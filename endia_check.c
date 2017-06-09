#include<stdio.h>
#include<stdlib.h>

int check_end_mthd1()
{
 int i = 1,endian = 0;
 char *c;
 c = (char*)&i;
 if(*c)
  endian = 1;
 return endian;
}

int check_end_mthd2()
{
 int endian = 0;
  union e 
  {
   int i;
   char c;
  };
 union e en;
 en.i = 1;
 if(en.c)
 endian = 1;
return endian;
}

int main()
{
if(check_end_mthd1() == 1)
printf("\nlittle endian");
else
printf("\nbig endian");
if(check_end_mthd2() == 1)
printf("\nlittle endian");
else
printf("\nbig endian");
return 0;
}


