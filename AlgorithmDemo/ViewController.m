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
    //bubbleSort(array, 10); // 
    //selectionSort(array, 10);
    //insertionSort(array, 10);
    //binaryInsertionSort(array, 10);
    //quickSort(array, 0, 9);
    //shellSort(array, 10);
    int tempArray[10];
    mergeSort(array, tempArray, 0, 9);
    
    for (int i =0; i< 10; i++) {
        NSLog(@"%d \n", array[i]);
    }
}



@end
