//
//  ArrayList.c
//  AlgorithmDemo
//
//  Created by chen on 2019/12/26.
//  Copyright © 2019 chen. All rights reserved.
//

#include "ArrayList.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/**
 创建列表

 @param capacity 容量
 @return ArrayList
 */
ArrayList *create_arr_list(int capacity) {
    if (capacity < 10) {
        capacity = 10;
    }
    ArrayList *arr = (ArrayList *)malloc(sizeof(ArrayList));
    arr->arr = (int *)malloc(sizeof(int) * capacity);
    arr->capacity = capacity;
    arr->index = 0;
    return arr;
}


/**
 容量不足时扩容

 @param arr arr description
 */
void expand_space(ArrayList *arr) {
    int *tmp, i, *p, *q;
    
    if (arr->index >= arr->capacity) {
        tmp = (int *)malloc(sizeof(int) * arr->capacity * 2);
        p = arr->arr;
        q = tmp;
        for (i = 0; i < arr->index; i++) {
            *q++ = *p++;
        }
        free(arr->arr);
        arr->arr = tmp;
        arr->capacity = arr->capacity * 2;
    }
}

/**
 特定位置插入元素

 @param arr 列表
 @param index 插入位置
 @param obj 被插入的元素
 @return return 成功返回0，失败返回-1
 */
int list_insert(ArrayList *arr, int index, int obj) {
    int i;
    if (index < 0 || index > arr->index) {
        return -1;
    }
    expand_space(arr);
    
    for (i = arr->index; i > index ; i--) {
        arr->arr[i] = arr->arr[i - 1];
    }
    arr->arr[index] = obj;
    arr->index++;
    return 0;
}


/**
 末尾添加元素

 @param arr 列表
 @param obj 被插入的元素
 @return return 成功返回0,失败返回-1
 */
int list_append(ArrayList *arr, int obj) {
    return list_insert(arr, arr->index, obj);
}

/**
 删除某个位置的元素

 @param arr 列表
 @param index 待删除元素的位置
 @return return 成功返回0,失败返回-1
 */
int list_removeAt(ArrayList *arr, int index) {
    int i;
    if (index < 0 || index >= arr->index) {
        return -1;
    }
    
    for (i = index; i < arr->index - 1; i++) {
        arr->arr[index] = arr->arr[index + 1];
    }
    arr->index--;
    return 0;
}


/**
 返回某个元素的位置

 @param arr 列表
 @param obj 查找的元素
 @return return 存在返回index,不存在则返回-1
 */
int list_index(ArrayList *arr, int obj) {
    int i;
    for (i = 0; i < arr->index; i++) {
        if (arr->arr[i] == obj) {
            return i;
        }
    }
    return -1;
}

/**
 是否包含某元素

 @param arr 列表
 @param obj 查找的元素
 @return return 包含返回true，否则返回false
 */
bool list_contain(ArrayList *arr, int obj) {
    int i;
    for (i = 0; i < arr->index; i++) {
        if (arr->arr[i] == obj) {
            return true;
        }
    }
    return false;
}


/**
 返回某个位置的元素值

 @param arr 列表
 @param index 位置
 @return return
 */
int list_get(ArrayList *arr, int index) {
    assert(index>=0 && index< arr->index);
    
    return arr->arr[index];
}

/**
 列表的大小(当前实际存储的元素个数)

 @param arr 列表
 @return return
 */
int list_size(ArrayList *arr) {
    return arr->index;
}

/**
 列表转数组

 @param arr 列表
 @return return 数组，调用者获得所有权，注释释放内存
 */
int *list_toArray(ArrayList *arr) {
    int *tmp, i, *p, *q;
    tmp = (int *)malloc(sizeof(int) * arr->index);
    p = arr->arr;
    q = tmp;
    for (i = 0; i < arr->index; i++) {
        *q++ = *p++;
    }
    return tmp;
}

/**
 释放列表

 @param arr 列表
 @return return value description
 */
int free_arr_list(ArrayList *arr){
    free(arr->arr);
    free(arr);
    arr = NULL;
    return 0;
}


/**
 打印列表

 @param arr 列表
 */
void print_arr_list(ArrayList *arr) {
    int i, t;
    printf("capacity=%d,index=%d\n", arr->capacity, arr->index);
    for (i = 0; i < arr->index; i++) {
        t = list_get(arr, i);
        printf("list[%d]=%d\n", i, t);
    }
}




