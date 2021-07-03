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
void clearQueue(Queue *queue)
{
QueueNode *t;
while(queue->start!=NULL)
{
t=queue->start;
queue->start=queue->start->next;
queue->size--;
free(t);
}
queue->end=NULL;
queue->size=0;
}

int main()
{
int x[10],y,max,min,range,z,i;
Queue *queues;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}

max=x[0];
min=x[0];
for(y=1;y<9;y++)
{
if(x[y]<min) min=x[y];
if(x[y]>max) max=x[y];
}
range=(max-min)+1;
queues=(Queue *)malloc(sizeof(Queue)*range);
for(y=0;y<range;y++)
{
initQueue(&queues[y]);
}
for(y=0;y<=9;y++)
{
z=x[y]-min;
addToQueue(&queues[z],x[y]);
}
i=0;
for(y=0;y<range;y++)
{
while(!isQueueEmpty(&queues[y]))
{
x[i]=removeFromQueue(&queues[y]);
i++;
}
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}
