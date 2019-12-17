//
//  NSMutableArray+ZYSort.h
//  Play-With-Sort-OC
//
//  Created by Chen on 2017/7/26.
//  Copyright © 2019年 chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ViewController.h"


typedef NS_ENUM(NSUInteger,ZYSortType){
    ZYSelectionSort,         //选择排序
    ZYBubbleSort,            //冒泡排序
    ZYInsertionSort,         //插入排序
    ZYMergeSort,             //归并排序
    ZYQuickSort,             //原始快速排序
    ZYIdenticalQuickSort,    //双路快速排序
    ZYQuick3WaysSort,        //三路快速排序
    ZYHeapSort,              //堆排序
};
typedef NSComparisonResult(^MBSortComparator)(id obj1, id obj2);


@interface NSMutableArray (ZYSort)

@property(nonatomic, strong) UIViewController *vc;


- (void)mb_sortUsingComparator:(MBSortComparator )comparator sortType:(MBSortType )sortType;
- (void)mb_exchangeWithIndexA:(NSInteger)indexA indexB:(NSInteger)indexB;

@end
