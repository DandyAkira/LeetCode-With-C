/*
 * @lc app=leetcode.cn id=528 lang=c
 *
 * [528] 按权重随机选择
 */

// @lc code=start

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    int *pre_sum;
    int presize;
    int total;
} Solution;


Solution* solutionCreate(int* w, int wSize) {

    Solution *sol = (Solution *)malloc(sizeof(Solution));
    int *pre = (int *)malloc(sizeof(int)*wSize);
    pre[0] = 0;

    int sum=0;

    for(int i=0; i<wSize; i++){
        sum += w[i];
        pre[i+1] = sum;
    }

    sol->total = sum;
    sol->pre_sum = pre;
    sol->presize = wSize+1;

    // for(int i=0; i<sol->length; i++){
    //     printf("%d ", sol->nums[i]);
    // }
    return sol;
}

int solutionPickIndex(Solution* obj) {
    int a;
    srand((unsigned)time(NULL));
    a = rand()%(obj->total) + 1;
    // 二分查找
    int s = 0; int e = obj->presize-1;
    while(s < e){
        int mid = (s+e)/2;
        if(obj->pre_sum[mid] < a){
            s = mid+1;
        } else {
            e = mid;
        }
    }
}

void solutionFree(Solution* obj) {
    free(obj->pre_sum);
    free(obj);
}


/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(w, wSize);
 * int param_1 = solutionPickIndex(obj);
 
 * solutionFree(obj);
*/
// @lc code=end

