//
//  Stack.c
//  AlgorithmDemo
//
//  Created by chen on 2019/12/26.
//  Copyright © 2019 chen. All rights reserved.
//

#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void initStack(stack *s){
    s->top=-1;
}

int isEmptyStack(stack s){
    if(s.top==-1){
        return 1;
    }
    return 0;
}

int isFullStack(stack s){
    if(s.top==MAXSIZE-1){
        return 1;
    }
    return 0;
}

void pushStack(stack *s,ElemType ele){
    if(!isFullStack(*s)){
        s->data[++s->top] = ele;
    }
    else{
        printf("栈已满\n");
    }
}

ElemType popStack(stack *s){
    assert(!isEmptyStack(*s));
    
    //if(!isEmpty(*s)){
        return s->data[s->top--];
    //}
    //printf("栈为空\n");
    
    //return -1;
}

int getStackSize(stack s){
    return s.top+1;
}
