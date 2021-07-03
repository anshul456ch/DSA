#include<string.h>
#include<stdlib.h>
#include<stdio.h>
/*
ptr for storing base address
cs represents collection size
es represents size of one element
*/
void bubbleSort(void *ptr,int cs,int es,int(*p2f)(void *,void *))
{
int e,f,m,w;
void *a,*b,*c;
c=(void *)malloc(es);
m=cs-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
e++;
f++;
}
m--;
}
free(c);   //to avoid memory leak
}

struct Student
{
int rollNumber;
char name[21];
};

int studentComparator(void *left,void *right)
{
struct Student *s1,*s2;
s1=(struct Student *)left;
s2=(struct Student *)right;
return s1->rollNumber-s2->rollNumber;
}

int main()
{
int req;
struct Student *s,*j;
int y;
printf("Enter your requirement :");
scanf("%d",&req);
if(req<=0)
{
printf("Invalid requirement\n");
return 0;
}
s=(struct Student *)malloc(sizeof(struct Student)*req);
j=s;
for(y=0;y<req;y++)
{
printf("Enter roll number : ");
scanf("%d",&(j->rollNumber));
printf("Enter name : ");
scanf("%s",j->name);
j++;
}
bubbleSort(s,req,sizeof(struct Student),studentComparator);
for(y=0;y<req;y++)
{
printf("Roll Number %d, Name %s\n",s[y].rollNumber,s[y].name);
}
free(s);
return 0;
}