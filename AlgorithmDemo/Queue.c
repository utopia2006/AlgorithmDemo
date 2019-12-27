//
//  Queue.c
//  AlgorithmDemo
//
//  Created by chen on 2019/12/27.
//  Copyright © 2019 chen. All rights reserved.
//

#include "Queue.h"
#include <stdlib.h>

//初始化队列
LinkQueue * InitQueue()
{
    LinkQueue * q = (LinkQueue*)malloc(sizeof(LinkQueue));
    q->front = q->rear = NULL;
    return q;
}

//判断队列是否为空
int EmptyQueue(LinkQueue * q)
{
    return q->front == NULL;
}

//入队
void Enqueue(LinkQueue *q, char data)
{
    node * n = (node *)malloc(sizeof(node));
    if(n == NULL)//内存分配失败
        return ;
    
    n->data = data;
    n->next = NULL;//尾插法，插入元素指向空
    if(q->rear == NULL)
    {
        q->front = n;
        q->rear = n;
    }
    else{
        q->rear->next = n;//让n成为当前的尾部节点下一节点
        q->rear= n;//尾部指针指向n
    }
    
}

//出队(删除队首元素)
void Dequeue(LinkQueue *q)
{
    node * n = q->front;
    if(q->front == NULL)//判断队列是否为空
        return ;
    
    if(q->front == q->rear)//是否只有一个元素
    {
        q->front = NULL;
        q->rear = NULL;
        free(n);
    }
    else{
        q->front = q->front->next;
        free(n);
    }
    
}

//打印队列
void Display(LinkQueue * q)
{
    node * n = q->front;
    if(n == NULL)
    {
        return ;//队列为空
    }
    
    while(n != NULL)
    {
        printf("%c ",n->data);
        n = n->next;
    }
    printf("\n");
}
