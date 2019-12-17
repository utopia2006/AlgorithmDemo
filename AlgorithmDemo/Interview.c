//
//  Interview.c
//  AlgorithmDemo
//
//  Created by chen on 2019/12/17.
//  Copyright © 2019 chen. All rights reserved.
//

#include "Interview.h"
#include <stdbool.h>

int findInsertIndex(int array[], int L, int R, int value);

char *revertStr(char *str) {
    char *begin,*end;
    begin = end = str;
    
    while (*end != '\0') {
        end ++;
    }
    --end;
    
    char temp;
    while (begin < end) {
        temp = *end;
        *end = *begin;
        *begin = temp;
    }
    
    return str;
}

// 冒泡排序（n-1趟）
void bubbleSort(int array[], int n) {
    for (int i=0; i< n-1; i++) {
        bool swaped = false;
        for (int j=0; j< n -1 -i; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                swaped = true;
            }
        }
        if (!swaped) {
            break;
        }
    }
    
}

// 选择排序(n-1趟)
void selectionSort(int array[], int n) {
    for (int i=0; i < n-1; i++) {
        int min = array[i];
        int index = i;
        for (int j=i+1; j < n; j++) {
            if (array[j] < min) {
                min = array[j];
                index = j;
            }
        }
        if (index != i) {
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }
    
}

// 插入排序(n-1趟)
// Reference: https://www.jianshu.com/p/7cf0656e76dd
void insertionSort(int array[], int n) {
    for (int i=1; i< n; i++) {
        if (array[i]<array[i-1]){
            int temp = array[i];
            for (int j=i;j>=0;j--){
                if (j>0 && array[j-1]>temp) {
                    array[j]=array[j-1];
                }else {
                    array[j]=temp;
                    break;
                }
            }
        }
    }
}

/**
 * 折半插入排序
 */
void binaryInsertionSort(int array[], int n) {
    
    for(int i = 1; i < n; i++) {
        int temp = array[i];
        // 通过二分查找找到插入的位置
        int insertIndex = findInsertIndex(array, 0, i - 1, array[i]);
        // 插入位置之后的元素依次向后移动
        for(int j = i; j > insertIndex; j--) {
            array[j] = array[j - 1];
        }
        // 更新插入位置的值
        array[insertIndex] = temp;
    }
    
}

/**
 * 在有序数组 nums 的[L, R]部分上，找到 value 的插入位置
 */
int findInsertIndex(int array[], int L, int R, int value) {
    
    while(L <= R) {
        int mid = L + ((R - L) / 2);
        if(value > array[mid]) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    
    return L;
    
}
