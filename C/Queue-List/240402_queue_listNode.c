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

 /* ����һ������ */
void initQueue(LinkQueue *q)
{
   /* ���ڴ��д���һ��ͷ�ڵ㣬�ն���ʱfront��rear��ָ��ͷ���*/
    q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));

    if(!q->front)
        exit(0);
    q->front->next = NULL;
}

// ����в�����ʱ�临�Ӷ�ΪO(1)
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

// �����в���
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

//����һ������
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

/* ��дһ�������У���������һ���ַ�����#��Ϊ������־��Ȼ�󽫶����е�Ԫ����ʾ����Ļ�� */