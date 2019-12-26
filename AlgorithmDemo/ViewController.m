//
//  ViewController.m
//  AlgorithmDemo
//
//  Created by chen on 2019/12/17.
//  Copyright © 2019 chen. All rights reserved.
//

#import "ViewController.h"
#import "InterviewSort.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    int array[10] = {23, 38, 29, 93, 3, 87,24,76,  2, 42};
    int len = (int)sizeof(array)/ sizeof(*array);
    //bubbleSort(array, len);
    //selectionSort(array, len);
    //insertionSort(array, len);
    //binaryInsertionSort(array, len);
    //quickSort(array, 0, len-1);
    //shellSort(array, len);
    //int tempArray[10];
    //mergeSort(array, tempArray, 0, 9);
    //radixSort(array, len);
    //heapSort(array, len);
    //countSort(array, len);
    bucketSort(array, len);
    
    for (int i =0; i< 10; i++) {
        NSLog(@"%d \n", array[i]);
    }
}



@end
