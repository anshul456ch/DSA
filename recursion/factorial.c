#include<stdio.h>
int fact(int p)
{
int num;
if(p==1) return 1;
num=fact(p-1)*p;
return num;
}

int main()
{
printf("Factorial of 5 is : %d\n",fact(5));
return 0;
}