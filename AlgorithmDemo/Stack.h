//
//  Stack.h
//  AlgorithmDemo
//
//  Created by chen on 2019/12/26.
//  Copyright © 2019 chen. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#define MAXSIZE 100
#define ElemType int

typedef struct{
    ElemType data[MAXSIZE];
    int top;
}stack;

void initStack(stack *s);
int isEmptyStack(stack s);
int isFullStack(stack s);
void pushStack(stack *s,ElemType ele);
ElemType popStack(stack *s);
int getStackSize(stack s);

#endif /* Stack_h */
