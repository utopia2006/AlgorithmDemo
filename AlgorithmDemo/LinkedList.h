//
//  LinkedList.h
//  AlgorithmDemo
//
//  Created by chen on 2019/12/26.
//  Copyright © 2019 chen. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>

// 定义链表节点
typedef struct _LinkNode {
    int data;
    struct _LinkNode * next;
} LinkNode;

// 定义链表结构
typedef struct _LinkList {
    LinkNode *head; //链表的头指针
    LinkNode *trail;//链表的尾部指针
    unsigned long length;//链表的当前长度
} LinkList;

LinkList *create_link_list(void);
int link_list_insert(LinkList* pList,int pData,long index);
int link_list_getAt(LinkList *pList,unsigned int index,int *value);
void link_list_removeAt(LinkList* pList,unsigned long index);
void link_list_free(LinkList* pList);
void print_link_list(LinkList *pList);

#endif /* LinkedList_h */
