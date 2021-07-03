#include<stdio.h>
int main()
{
int a,b,c;
printf("Enter first number :");
scanf("%d",&a);
printf("Enter second number :");
scanf("%d",&b);
while(a%b!=0)
{
c=a%b;
a=b;
b=c;
}
printf("GCD is : %d",b);
return 0;
}