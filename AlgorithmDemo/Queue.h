//
//  Queue.h
//  AlgorithmDemo
//
//  Created by chen on 2019/12/27.
//  Copyright © 2019 chen. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>

typedef char ElemType;

//定义节点
typedef struct node{
    ElemType data;
    struct node * next;
} node;

//定义队列（保存队首和队尾指针）
typedef struct queue_link {
    node * front;
    node * rear;
} LinkQueue;

LinkQueue * InitQueue(void);
int EmptyQueue(LinkQueue * q);
void Enqueue(LinkQueue *q, char data);
void Dequeue(LinkQueue *q);

#endif /* Queue_h */
