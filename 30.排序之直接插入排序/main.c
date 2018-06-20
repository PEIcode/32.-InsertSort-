//
//  main.c
//  30.排序之直接插入排序
//
//  Created by sunny&pei on 2018/6/20.
//  Copyright © 2018年 sunny&pei. All rights reserved.
//


/* 直接插入排序 ：是将一个记录插入到已经排好序的有序表中，从而得到一个新的，记录数增加1的有序表*/
#include <stdio.h>
#define MAXSIZE 10 /* 用于要排序数组个数最大值，可根据需要修改*/
typedef struct{
    int r[MAXSIZE+1];/* 用于存储要排序的数组，r[0]用作哨兵或临时变量*/
    int length; /* 用于记录顺序表的长度*/
}Sqlist;

void InsertSort(Sqlist *L){
    int i,j;
    for (i = 2; i<L->length; i++) {
        if (L->r[i]<L->r[i-1]) {
            L->r[0] = L->r[i];
            //方案一
//            for (j = i-1;L->r[j]>L->r[0] ; j--) {
//                L->r[j+1] = L->r[j];
//            }
            //方案二
            j = i-1;
            while (L->r[0]<L->r[j]) {
                L->r[j+1] = L->r[j];
                j--;
            }
            L->r[j+1] = L->r[0];
        }
    }
}
/**
 总结：直接插入排序，当序列中的记录基本有序的时候或待排序记录较少时，他是最佳的排序方法。
 最好情况下，正序，比较次数n-1，移动次数2（n-1），时间复杂度为O(n)；
 最坏情况下，逆序，O(n2)
 */
int main(int argc, const char * argv[]) {
    // insert code here...
    Sqlist L;
    L.length = 10;
    L.r[1] = 5;
    L.r[2] = 4;
    L.r[3] = 3;
    L.r[4] = 10;
    L.r[5] = 7;
    L.r[6] = 8;
    L.r[7] = 9;
    L.r[8] = 6;
    L.r[9] = 1;
    InsertSort(&L);
    for (int i = 1; i<L.length; i++) {
        printf("%d\n",L.r[i]);
    }
    return 0;
}
