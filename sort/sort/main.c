//
//  main.c
//  sort
//
//  Created by Taro on 2017/3/21.
//  Copyright © 2017年 Taro. All rights reserved.
//

#include <stdio.h>
#include <time.h>


void GuiBing(int sort[], int count){
    int temp ;
    for (int i = 0; i<count-1; i=i+2) {
        if (sort[i] > sort[i+1]) {
            temp = sort[i];
            sort[i] = sort[i+1];
            sort[i+1] = temp;
        }
    }
}


void MaoPao(int sort[], int count){
    int temp;
    for (int j = 0; j < count; j++) {
        for (int i = 0; i < count-1; i++) { //因为要与i+1判断，所以只要循环到count-1
            if (sort[i] > sort[i+1]) {
                temp = sort[i];
                sort[i] = sort[i+1];
                sort[i+1] = temp;
            }
        }
    }
}




void Qsort(int sort[], int left, int right){
    
    if (left > right) {
        return;
    }
    
    int i = left;
    int j = right;
    int key = sort[i];
    
    while (i < j) {
        while (i < j && key <= sort[j]) {
            j--;
        }
        sort[i] = sort[j];
        while (i < j && key >= sort[i]) {
            i++;
        }
        sort[j] = sort[i];
    }
    
    sort[i] = key;
    Qsort(sort, left, i-1);
    Qsort(sort, i+1, right);
}




int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    int sort[] = {49, 38, 65, 97, 76, 13, 27};
    clock_t start, end;
    start = clock();
    Qsort(sort, 0, 6);
    end = clock();
    printf("快排 : %.4fms\n ", (double)(end - start)*1000/ CLOCKS_PER_SEC);
    
    for (int i = 0; i < 7; i++) {
        printf("%3d",sort[i]);
    }
    printf("\n");
    
    
     int sort1[] = {49, 38, 65, 97, 76, 13, 27};
    MaoPao(sort1, 7);
    for (int i = 0; i < 7; i++) {
        printf("%3d",sort1[i]);
    }
    printf("\n");
    return 0;
}
