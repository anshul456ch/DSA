#include<stdio.h>
int fact(int p)
{
if(p==1) return 1;
return fact(p-1)*p; 
}

int main()
{
int num;
printf("Enter a number : ");
scanf("%d",&num);
printf("Factorial of %d is : %d ",num,fact(num));
return 0;
}