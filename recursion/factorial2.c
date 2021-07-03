#include<stdio.h>
int fact(int p)
{
if(p==1) return 1;
return fact(p-1)*p; 
}

int main()
{
printf("Factorial of 5 is : %d\n",fact(5));
return 0;
}