#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef char ElemType;

typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePrt;

typedef struct 
{
    QueuePrt front,rear;
}LinkQueue;

 /* 创建一个队列 */
void initQueue(LinkQueue *q)
{
   /* 在内存中创建一个头节点，空队列时front和rear都指向头结点*/
    q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));

    if(!q->front)
        exit(0);
    q->front->next = NULL;
}

// 入队列操作，时间复杂度为O(1)
void InsertQueue(LinkQueue *q, ElemType e)
{
    QueuePrt p;
    p = (QueuePrt)malloc(sizeof(QNode));
    if(p == NULL)
    {
        exit(0);
    }
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

// 出队列操作
void  DeleteQueue(LinkQueue *q, ElemType *e)
{
    QueuePrt p;
    if(q->front == q->rear)
    {
        return;
    }
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear = p)
    {
        q->rear = q->front;
    }
    free(p);
}

//销毁一个队列
void DestroyQueue(LinkQueue *q)
{
    while (q->front)
    {
      q->rear = q->front->next;
      free(q->front);
      q->front = q->rear;
    }
    q->rear = NULL;
    
}

/* 编写一个链队列，任意输入一串字符，以#作为结束标志，然后将队列中的元素显示到屏幕上 */