#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 20
typedef char ElemType;

typedef struct 
{
    ElemType *base;/* 用于存放内存分配基地址，也可以用数组存放 */
    int front;
    int rear;
}cycleQueue;

//初始化一个循环队列
void initQueue(cycleQueue *q)
{
    q->base = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));
    if(!q->base)
        exit(0);
    q->front = q->rear = 0;
}

void InsertQueue(cycleQueue *q, ElemType e)
{
    if((q->rear + 1) % MAXSIZE == q->front)//判断队列是否已满，但是实际好像此时还剩一个空位
        return;
    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;

}

//出队列操作
void DeleteQueue(cycleQueue* q, ElemType *e)
{
    if(q->front == q->rear)
        return;
    *e = q->base[q->front];
    q->front = (q->front + 1) % MAXSIZE;
}
