//
//  main.c
//  wangyi-1
//
//  Created by Taro on 2017/3/21.
//  Copyright © 2017年 Taro. All rights reserved.
//

#include <stdio.h>

void xipai(int sort[], int count){
    int sortA[10];
    int sortB[10];
    int i = 0;
    
    while (i<count) {
        sortA[i] = sort[i];
        sortB[i] = sort[i+count];
        i++;
    }
    
    
    while (i>0) {

        sort[2*i-1] = sortB[i];
        sort[2*i-2] = sortA[i];
        i--;
        
    }
    
   
  
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int sort[] = {1, 2, 3, 4, 5, 6};
    xipai(sort, 3);
    
    for (int i = 0; i<6; i++) {
        printf("%3d",sort[i]);
    }
    
    printf("\n");
    
    
    return 0;
}
