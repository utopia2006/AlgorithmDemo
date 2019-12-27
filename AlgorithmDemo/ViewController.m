//
//  ViewController.m
//  AlgorithmDemo
//
//  Created by chen on 2019/12/17.
//  Copyright © 2019 chen. All rights reserved.
//

#import "ViewController.h"
#import "InterviewSort.h"
#include "LinkedList.h"
#include "RedBlackTree.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    //[self testSort];
    //[self testLinkList];
    [self testRedBlackTree];
}

- (void)testSort {
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

- (void)testLinkList {
    LinkList *pList = create_link_list();
    int array[10] = {23, 38, 29, 93, 3, 87,24,76,  2, 42};
    int len = (int)sizeof(array)/ sizeof(*array);
    for (int i=0; i< len ; i++) {
        link_list_insert(pList, array[i], -1);
    }
    link_list_removeAt(pList, 0);
    
    print_link_list(pList);
}


#define CHECK_INSERT 0    // "插入"动作的检测开关(0，关闭；1，打开)
#define CHECK_DELETE 0    // "删除"动作的检测开关(0，关闭；1，打开)
#define LENGTH(a) ( (sizeof(a)) / (sizeof(a[0])) )

- (void)testRedBlackTree {
    int a[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
    int i, ilen=LENGTH(a);
    RBRoot *root=NULL;
    
    root = create_rbtree();
    printf("== 原始数据: ");
    for(i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    for(i=0; i<ilen; i++)
    {
        insert_rbtree(root, a[i]);
#if CHECK_INSERT
        printf("== 添加节点: %d\n", a[i]);
        printf("== 树的详细信息: \n");
        print_rbtree(root);
        printf("\n");
#endif
    }
    
    printf("== 前序遍历: ");
    preorder_rbtree(root);
    
    printf("\n== 中序遍历: ");
    inorder_rbtree(root);
    
    printf("\n== 后序遍历: ");
    postorder_rbtree(root);
    printf("\n");
    
    if (rbtree_minimum(root, &i)==0)
        printf("== 最小值: %d\n", i);
    if (rbtree_maximum(root, &i)==0)
        printf("== 最大值: %d\n", i);
    printf("== 树的详细信息: \n");
    print_rbtree(root);
    printf("\n");
    
#if CHECK_DELETE
    for(i=0; i<ilen; i++)
    {
        delete_rbtree(root, a[i]);
        
        printf("== 删除节点: %d\n", a[i]);
        if (root)
        {
            printf("== 树的详细信息: \n");
            print_rbtree(root);
            printf("\n");
        }
    }
#endif
    
    destroy_rbtree(root);
}


@end
