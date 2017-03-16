//
//  main.c
//  DFS&BFS
//
//  Created by Taro on 2017/3/15.
//  Copyright © 2017年 Taro. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char map[101][101];
int m, n, sum;


void dfs(int i, int j){
    if (map[i][j]!='@' || i<0 || j<0 || i>m || j>n  ) return;
    
    else{
        map[i][j] = '*';
        dfs(i-1, j-1);
        dfs(i-1, j);
        dfs(i-1, j+1);
        dfs(i, j-1);
        dfs(i, j+1);
        dfs(i+1, j-1);
        dfs(i+1, j);
        dfs(i+1, j+1);
    }
    
}




int main() {
    // insert code here...
    int i, j;
    
    while (scanf("%d%d",&m, &n) != EOF) {
        if (m==0 || n==0) {
            break;
        }
        sum = 0;
//        getchar();
        for (i = 0; i < m; i++) {
            scanf("%s",&map[i]);
//            for (j = 0; j < n; j++) {
//                scanf("%s",&map[i][j]);
//                getchar();
//            }
        }
        
        
//        for (i = 0; i<m; i++) {
//            for (j = 0; j<n; j++) {
//                printf("a- %c\n",map[i][j]);
//            }
//        }
        
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (map[i][j] == '@') {
                    dfs(i, j);
                    sum++;
                    
                }
            }
        }
        printf("%d\n",sum);
        
    }
    
    
    
    
    return 0;
}
