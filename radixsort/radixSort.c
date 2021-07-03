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


typedef struct __stackTop
{
struct __stackNode *top;
int size;
}Stack;
typedef struct __stackNode
{
int data;
struct __stackNode *next;
}StackNode;
void init(Stack *stack)
{
stack->top=NULL;
stack->size=0;
}
void push(Stack *stack,int num)
{
StackNode *t;
t=(StackNode *)malloc(sizeof(StackNode));
t->data=num;
t->next=stack->top;
stack->top=t;
stack->size=stack->size+1;
}
int pop(Stack *stack)
{
StackNode *t;
int data;
data=stack->top->data;
t=stack->top;
stack->top=stack->top->next;
free(t);
stack->size=stack->size-1;
return data;
}
int isEmpty(Stack *stack)
{
return stack->top==NULL;
}


int main()
{
int x[10],y,e,f,i,num,largest,dc,k,j,count;
Stack stack;
Queue queuesOne[10];
Queue queuesTwo[10];
for(i=0;i<=9;i++)
{
initQueue(&queuesOne[i]);
initQueue(&queuesTwo[i]);
}
init(&stack);
for(y=0;y<=9;y++)
{
printf("Enter the number : ");
scanf("%d",&x[y]);
}
largest=x[0];
for(y=1;y<=9;y++)
{
num=x[y];
if(num<0) num=x[y]*-1;
if(num>largest) largest=num;
}
dc=1;
num=largest;
while(num>9)
{
num=num/10;
dc++;
}
e=10;
f=1;
k=1;
while(k<=dc)
{
y=0;
while(y<=9)
{
num=x[y];
i=(num%e)/f;
if(i<0 || x[y]<0)
{
 addToQueue(&queuesTwo[i*-1],num);
}
else addToQueue(&queuesOne[i],num);
y++;
} 
i=0;
y=0;

while(y<=9)
{
while(!isQueueEmpty(&queuesTwo[y]))
{
num=removeFromQueue(&queuesTwo[y]);
x[i]=num;
i++;
}
y++;
}
y=0;
while(y<=9)
{
while(!isQueueEmpty(&queuesOne[y]))
{
num=removeFromQueue(&queuesOne[y]);
x[i]=num;
i++;
}
y++;
}
e=e*10;
f=f*10;
k++;
}
count=0;
for(y=0;y<=9;y++)
{
if(x[y]<0) count++;
} 
e=0;
while(e<count)
{
push(&stack,x[e]);
e++;
}
e=0;
while(e<count)
{
f=pop(&stack);
x[e]=f;
e++;
}
for(y=0;y<=9;y++)
{
printf("%d\n",x[y]);
}
return 0;
}