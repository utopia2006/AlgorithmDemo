//
//  LinkedList.c
//  AlgorithmDemo
//
//  Created by chen on 2019/12/26.
//  Copyright © 2019 chen. All rights reserved.
//

#include "LinkedList.h"
#include <stdlib.h>

LinkList *create_link_list() {
    LinkList *pList = (LinkList *)malloc(sizeof(LinkList));
    if (pList == NULL) {
        return NULL;
    }
    
    pList->length = 0;
    pList->head = NULL;
    pList->trail = NULL;
    return pList;
}

int link_list_insert(LinkList* pList,int pData,long index) {
    long i = 0;
    if(pList == NULL)
        return -1;
    if(index < -1 || (index > pList->length && index != -1))
    {
        return -1;
    }
    
    //判断是否是首次插入
    if(pList->length == 0)
    {
        LinkNode* pNode = (LinkNode*)malloc(sizeof(LinkNode));
        if(pNode == NULL)
            return -1;
        pNode->data = pData;
        pNode->next = NULL;
        
        pList->head = pNode;
        pList->trail = pNode;
        pList->length++;
        return 0;
    }
    else
    {
        if(-1 == index)//从末尾处插入
        {
            //创建节点
            LinkNode* pNode = (LinkNode*)malloc(sizeof(LinkNode));
            if(pNode == NULL)
                return -1;
            pNode->data = pData;
            pNode->next = NULL;
            //将节点加到末尾处
            pList->trail->next = pNode;
            pList->trail = pNode;
            pList->length++;
        }
        else if(0 == index) //从开始处插入
        {
            //创建节点
            LinkNode* pNode = (LinkNode*)malloc(sizeof(LinkNode));
            if(pNode == NULL)
                return -1;
            pNode->data = pData;
            pNode->next = pList->head;
            //将节点加载到头部
            pList->head = pNode;
            pList->length++;
            return 0;
        }
        else//指定位置插入
        {
            //后期可以使用快速查找算法优化
            LinkNode *pNode = pList->head;
            LinkNode *preNode = NULL;
            i=0;
            while(pNode != NULL)
            {
                if(index == i)//查找到要插入的位置节点
                {
                    //创建节点
                    LinkNode* pCurrentNode = (LinkNode*)malloc(sizeof(LinkNode));
                    if(pCurrentNode == NULL)
                        return -1;
                    
                    // 新节点的next是谁
                    if (index == pList->length) {
                        pCurrentNode->next = NULL;
                    } else {
                        pCurrentNode->next = pNode;
                    }
                    
                    // 新节点的pre是谁
                    if (preNode != NULL) {
                        preNode->next = pCurrentNode;
                    } else {
                        pList->head = pCurrentNode;
                    }
            
                    pList->length++;
                    return 0;
                }
                
                preNode = pNode;
                pNode = pNode->next;
                i++;
            }
        }
    }
    
    return 0;
}


void link_list_removeAt(LinkList* pList,unsigned long index)
{
    if(pList == NULL)
    {
        return;
    }
    int i = 0;
    LinkNode *pNode = pList->head;
    LinkNode *preNode = NULL;
    while(pNode != NULL)
    {
        if(i == index)
        {
            //找到节点，开始删除
            if(preNode == NULL) //表示链表头部节点
            {
                LinkNode *head = pList->head;
                pList->head = head->next;
                free(head);//释放节点
                pList->length--;
            }
            else if(pNode->next == NULL)//表示链表尾部节点
            {
                LinkNode* trial = pList->trail;
                pList->trail = preNode;
                pList->trail->next = NULL;
                free(trial);//释放节点
                pList->length--;
            }
            else
            {
                //当前节点的上一个节点的下一个节点指向当前节点的下一个节点
                preNode->next = pNode->next;
                free(pNode);
                pList->length--;
            }
            return;
        }
        
        preNode = pNode;
        pNode = pNode->next;
        i++;
    }
}


/**
 获取某个位置的值

 @param pList 链表
 @param index 位置
 @param value 返回该位置的值
 @return return 成功返回0， 失败返回-1;
 */
int link_list_getAt(LinkList *pList,unsigned int index,int *value)
{
    if(pList == NULL)
    {
        return -1;
    }
    
    int i = 0;
    LinkNode *pNode = pList->head;
    while(pNode != NULL)
    {
        if(i == index)
        {
            *value= pNode->data;
            return 0;
        }
        
        pNode = pNode->next;
        i++;
    }
    
    return -1;
}

void link_list_clear(LinkList* pList)
{
    //将数据域置为空
    if(pList == NULL)
    {
        return;
    }
    
    // 从头部开始释放
    LinkNode *pNode = pList->head;
    LinkNode *nextNode = pNode->next;
    while (pNode != NULL) {
        free(pNode);
        pNode = nextNode;
        nextNode = pNode->next;
    }

    pList->length = 0;
    pList->head = NULL;
    pList->trail = NULL;
}

void link_list_free(LinkList* pList)
{
    if(pList == NULL)
    {
        return;
    }
    
    // 从头部开始释放
    LinkNode *pNode = pList->head;
    LinkNode *nextNode = pNode->next;
    while(pNode != NULL)
    {
        free(pNode);
        pNode = nextNode;
        nextNode = pNode->next;
    }
    pList->length = 0;
    pList->head = NULL;
    pList->trail = NULL;
    free(pList);
    pList = NULL;
}

void print_link_list(LinkList *pList) {
    if (pList == NULL) {
        return;
    }
    
    LinkNode *pNode = pList->head;
    int index =0;
    while (pNode != NULL) {
        printf("list[%d]=%d\n", index, pNode->data);
        //printf("list[%d]=%d\n", i, t);
        pNode = pNode->next;
        index ++;
    }
    
}

