/*
 * @lc app=leetcode.cn id=2100 lang=c
 *
 * [2100] 适合打劫银行的日子
 */

// @lc code=start

#include<stdio.h>
#include<stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


/*
    DP:
        维护一个二维数组DP[securitySize][2]
        DP[i][0] 记录 i 左侧 非递增 数列长度； DP[i][1] 记录 i 右侧 非递减 数列长度
        security[i] > security[i-1] 时 DP[i][0] = 0
        security[i] <= security[i-1] 时 DP[i][0] = DP[i][i-1] + 1
        DP[i][1] 同理
        只有当 DP[i][0]， DP[i][1] 同时大于 time，记录一个答案
*/

int* goodDaysToRobBank(int* security, int securitySize, int time, int* returnSize){
    *returnSize = 0;
    if(securitySize-2*time <= 0){
        return (int *)malloc(sizeof(int)*0);
    }

    *returnSize = 0;
    int dp[securitySize][2];
    dp[0][0] = 0;
    dp[securitySize-1][1] = 0;
    for(int i=1; i<securitySize; i++){
        if(security[i] <= security[i-1]) dp[i][0] = dp[i-1][0] + 1;
        else dp[i][0] = 0;
    }
    for(int j=securitySize-2; j>=0; j--){
        if(security[j] <= security[j+1]) dp[j][1] = dp[j+1][1] + 1;
        else dp[j][1] = 0;
    }
    int tmp[securitySize-2*time];
    for(int k=0; k<securitySize; k++){
        if(dp[k][0] >= time && dp[k][1] >= time){
            tmp[*returnSize] = k;
            (*returnSize)++;
        }
    }
    int *res = (int *)malloc(sizeof(int)*(*returnSize));
    for(int i=0; i<(*returnSize); i++){
        res[i] = tmp[i];
    }
    return res;
}
// @lc code=end

