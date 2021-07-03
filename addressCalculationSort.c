#include<stdio.h>
#include<stdlib.h>
typedef struct _queue_node
{
int num;
struct _queue_node *next;
}QueueNode;
typedef struct _queue
{
QueueNode *start;
QueueNode *end;
int size;
}Queue;
void initQueue(Queue *queue)
{
queue->start=NULL;
queue->end=NULL;
queue->size=0;
}
int isQueueEmpty(Queue *queue)
{
return queue->size==0;
}
void addToQueue(Queue *queue,int num)
{
QueueNode *t;
t=(QueueNode *)malloc(sizeof(QueueNode));
t->num=num;
t->next=NULL;
if(queue->start==NULL)
{
queue->start=t;
queue->end=t;
}
else
{
queue->end->next=t;
queue->end=t;
}
queue->size++;
}
int removeFromQueue(Queue *queue)
{
int num;
QueueNode *t;
num=queue->start->num;
t=queue->start;
queue->start=queue->start->next;
if(queue->start==NULL) queue->end=NULL;
free(t);
queue->size--;
return num;
}
int findKey(int dc,int num)
{
int f=1,div=1;
while(f<dc)
{
div=div*10;
f++;
}
f=num/div;

return f;
}

int main()
{
int x[10],y,dc,num,largest,key,tmp[10];
Queue queues[10];
for(y=0;y<=9;y++)
{
initQueue(&queues[y]);
}

for(y=0;y<=9;y++)
{
printf("Enter the number :");
scanf("%d",&x[y]);
}

largest=x[0];
for(y=1;y<=9;y++)
{
if(x[y]>largest) largest=x[y];
}

dc=1;
num=largest;
while(num>9)
{
num=(num/10);
dc++;
}
y=0;
while(y<=9)
{
 key=findKey(dc,x[y]);
 addToQueue(&queues[key],x[y]);
y++;
}
for(y=0;y<=9;y++)
{
int i=0;
while(!isQueueEmpty(&queues[y]))
{
tmp[i]=removeFromQueue(&queues[y]);
i++;
}
if(i==1)
{
addToQueue(&queues[y],tmp[0]);
}
else
{
int e,f,num,g;
e=0;
while(e<i-1)
{
 f=e+1;
 while(f<i)
 {
 if(tmp[e]>tmp[f])
 {
 g=tmp[e];
 tmp[e]=tmp[f];
 tmp[f]=g;
 }
 f++;
 }
e++;
}
for(int k=0;k<i;k++)
{
addToQueue(&queues[y],tmp[k]);
}
}
}
int i=0;
for(y=0;y<=9;y++)
{
while(!isQueueEmpty(&queues[y]))
{
x[i]=removeFromQueue(&queues[y]);
i++;
}
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}