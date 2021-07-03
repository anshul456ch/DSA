#include<stdio.h>
int gcd(int e,int f)
{
if(f==0)
{
return e;
}
else if(e>=f && f>0)
{
return gcd(f,(e%f));
}
}
int main()
{
int a,b,c,lcm;
printf("Enter two numbers :");
scanf("%d%d",&a,&b);
c=gcd(a,b);
lcm=(a*b)/c;
printf("GCD of %d and %d is : %d",a,b,c);
printf("\nLCM of %d and %d is : %d",a,b,lcm);
return 0;
}