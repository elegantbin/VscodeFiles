#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 20
typedef char ElemType;

typedef struct 
{
    ElemType *base;/* ���ڴ���ڴ�������ַ��Ҳ������������ */
    int front;
    int rear;
}cycleQueue;

//��ʼ��һ��ѭ������
void initQueue(cycleQueue *q)
{
    q->base = (ElemType*)malloc(MAXSIZE*sizeof(ElemType));
    if(!q->base)
        exit(0);
    q->front = q->rear = 0;
}

void InsertQueue(cycleQueue *q, ElemType e)
{
    if((q->rear + 1) % MAXSIZE == q->front)//�ж϶����Ƿ�����������ʵ�ʺ����ʱ��ʣһ����λ
        return;
    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;

}

//�����в���
void DeleteQueue(cycleQueue* q, ElemType *e)
{
    if(q->front == q->rear)
        return;
    *e = q->base[q->front];
    q->front = (q->front + 1) % MAXSIZE;
}
