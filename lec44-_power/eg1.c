#include<stdio.h>
int power(int e,int f)
{
int i,pw;
pw=1;
for(int i=1;i<=f;i++) pw*=e;
return pw;
}

int main()
{
int x,y;
printf("Enter a number : ");
scanf("%d",&x);
printf("Enter power : ");
scanf("%d",&y);
printf("%d^%d is %d",x,y,power(x,y));
return 0;
}