/*
 * @lc app=leetcode.cn id=22 lang=c
 *
 * [22] 括号生成
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void DFS(int n, int leftnum, int rightnum, char *str, int *returnSize, char ** res){
    
    // 终止情况
    if(leftnum == n && rightnum == n){
        char *ans = (char *)malloc(sizeof(char)*(2*n+1));
        strcpy(ans, str);
        ans[2*n] = '\0';
        res[(*returnSize)++] = ans;
        return;
    }

    // 括号没用完
    if(leftnum < n){
        // 放左括号
        str[leftnum+rightnum] = '(';
        DFS(n, leftnum+1, rightnum, str, returnSize, res);

        // 放右括号 （rightnum < leftnum）
        if(rightnum < leftnum){
            str[leftnum+rightnum] = ')';
            DFS(n, leftnum, rightnum+1, str, returnSize, res); 
        }
    }

}

char ** generateParenthesis(int n, int* returnSize){
    int fullsize = pow(2, 2*n);
    char ** res = (char **)malloc(sizeof(char *) * fullsize);
    *returnSize = 0;
    char *str = (char *)malloc(sizeof(char) * (2*n+1));
    DFS(n, 0, 0, str, returnSize, res);
    return res;
}
// @lc code=end

int main(int argc, char const *argv[])
{
    int *returnSize;
    char ** res = generateParenthesis(3, returnSize);
    int size = (int)(sizeof(res)/sizeof(char *));
    for(int i=0; i<size; i++){
        printf("%s\n", res[i]);
    }
    return 0;
}


