//
//  ArrayList.h
//  AlgorithmDemo
//
//  Created by chen on 2019/12/26.
//  Copyright © 2019 chen. All rights reserved.
//

#ifndef ArrayList_h
#define ArrayList_h

#include <stdio.h>

typedef struct arr_list {
    int *arr;  // 内部数组
    int index; // 实际数据大小
    int capacity;  // 预分配空间大小
} ArrayList;

ArrayList *create_arr_list(int n);
int list_append(ArrayList *arr, int obj);
int list_get(ArrayList *arr, int index);
int list_size(ArrayList *arr);
int free_arr_list(ArrayList *arr);
int *list_toArray(ArrayList *arr);

#endif /* ArrayList_h */
