//
//  InterviewSort.h
//  AlgorithmDemo
//
//  Created by chen on 2019/12/17.
//  Copyright © 2019 chen. All rights reserved.
//

#ifndef InterviewSort_h
#define InterviewSort_h

#include <stdio.h>
#include <stdlib.h>

// 参考资料
// 1、https://www.runoob.com/w3cnote/ten-sorting-algorithm.html
// 2、https://www.cnblogs.com/yadiel-cc/p/11829360.html
// 3、https://github.com/hustcc/JS-Sorting-Algorithm

// 八大排序算法，平均时间复杂度、最坏时间复杂度，空间复杂度，稳定排序与非稳定排序

//排序算法稳定性的定义: 能保证两个相等的数，经过排序之后，其在序列的前后位置顺序不变。（A1=A2，排序前A1在A2前面，排序后A1还在A2前面）
//稳定性排序：冒泡排序，插入排序、归并排序、基数排序
//不稳定性排序：选择排序、快速排序、希尔排序、堆排序


// 翻转字符串
char *revertStr(char *str);

// 冒泡排序
void bubbleSort(int array[], int n);
// 选择排序
void selectionSort(int array[], int n);

// 简单插入排序
void insertionSort(int array[], int n);
// 折半插入排序
void binaryInsertionSort(int array[], int n);

// 希尔排序（插入排序的一种优化，注意增量序列的选择）
void shellSort(int arr[], int n);

// 快速排序
void quickSort(int *a, int left, int right);

// 归并排序
void mergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex);

// 基数排序
void radixSort(int data[], int n);

// 堆排序
void heapSort(int arr[], int len);


#endif /* Interview_h */
