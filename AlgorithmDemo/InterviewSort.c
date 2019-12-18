//
//  InterviewSort.c
//  AlgorithmDemo
//
//  Created by chen on 2019/12/17.
//  Copyright © 2019 chen. All rights reserved.
//

#include "InterviewSort.h"
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

/**
 希尔排序
 平均时间复杂度O(n的1.3次方,不确定，具体与增量序列的选择有关)
 最差时间复杂度O(n2)
 空间复杂度O(log2n)
 
 @param arr 数组
 @param n 元素个数
 */
void shellSort(int arr[], int n) {
    // 计算increment sequence : 1, 4, 13, 40, 121, 364, 1093...
    int h = 1;
    while(h < n/3)
        h = 3*h +1;
    
    while(h>=1) {
        for (int i=h; i < n; i++) {
            // 对arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]...使用插入排序
            int e = arr[i];
            int j;
            for (j=i; j>=h && e < arr[j-h]; j-= h)
                arr[j] = arr[j-h];
            arr[j] = e;
        }
        
        h /= 3;
    }
}


/**
 快速排序
 平均时间复杂度O(nlog2n)
 最差时间复杂度O(n2)
 空间复杂度O(log2n)
 
 @param a 数组
 @param left 左游标
 @param right 右游标
 */
void quickSort(int *a, int left, int right) {
    int i, j, t, temp;
    if(left > right)
        return;
    
    temp = a[left]; //temp中存的就是基准数
    i = left;
    j = right;
    while(i != j) { //顺序很重要，要先从右边开始找
        while(a[j] >= temp && i < j)
            j--;
        while(a[i] <= temp && i < j)//再找右边的
            i++;
        if(i < j)//交换两个数在数组中的位置
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //最终将基准数归位
    a[left] = a[i];
    a[i] = temp;
    quickSort(a, left, i-1);//继续处理左边的，这里是一个递归的过程
    quickSort(a, i+1, right);//继续处理右边的 ，这里是一个递归的过程
}

void _merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}


/**
 归并排序
 平均时间复杂度O(nlog2n)
 空间复杂度O(n)
 
 @param sourceArr sourceArr description
 @param tempArr tempArr description
 @param startIndex startIndex description
 @param endIndex endIndex description
 */
void mergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = startIndex + (endIndex-startIndex) / 2;//避免溢出int
        mergeSort(sourceArr, tempArr, startIndex, midIndex);
        mergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        _merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

int maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
    int maxData = data[0];              ///< 最大数
    /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
    for (int i = 1; i < n; ++i)
    {
        if (maxData < data[i])
            maxData = data[i];
    }
    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        //p *= 10; // Maybe overflow
        maxData /= 10;
        ++d;
    }
    return d;
}

// https://www.runoob.com/w3cnote/radix-sort.html

//void radixSort(int data[], int n)
//{
//    int d = maxbit(data, n);
//    int *tmp = new int[n];
//    int *count = new int[10]; //计数器
//    int i, j, k;
//    int radix = 1;
//    for(i = 1; i <= d; i++) //进行d次排序
//    {
//        for(j = 0; j < 10; j++)
//            count[j] = 0; //每次分配前清空计数器
//        for(j = 0; j < n; j++)
//        {
//            k = (data[j] / radix) % 10; //统计每个桶中的记录数
//            count[k]++;
//        }
//        for(j = 1; j < 10; j++)
//            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
//        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
//        {
//            k = (data[j] / radix) % 10;
//            tmp[count[k] - 1] = data[j];
//            count[k]--;
//        }
//        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
//            data[j] = tmp[j];
//        radix = radix * 10;
//    }
//    delete []tmp;
//    delete []count;
//}
