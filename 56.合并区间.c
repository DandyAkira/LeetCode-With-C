/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Interval {
    int start;
    int end;
} inter;

int compare(const void *a, const void *b){
    return (((inter *)a)->start - ((inter *)b)->start);
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    inter inters[intervalsSize];
    for(int i=0; i<intervalsSize; i++){
        inters[i].start = intervals[i][0];
        inters[i].end = intervals[i][1];
    }
    qsort(inters, intervalsSize, sizeof(inter), compare);
        for(int i=0; i<intervalsSize; i++){
            printf("[%d %d] ", inters[i].start, inters[i].end);
    }
    int ** res = (int **)malloc(sizeof(int *)*intervalsSize);
    *returnColumnSizes  = (int *)malloc(sizeof(int ) * intervalsSize);
    for(int i=0; i<intervalsSize; i++){
        if((*returnSize) == 0){
            int *tmp = (int *)malloc(sizeof(int)*2);
            tmp[0] = inters[i].start;
            tmp[1] = inters[i].end;
            res[(*returnSize)] = tmp;
            (*returnColumnSizes)[(*returnSize)] = 2;
            (*returnSize)++;
        } else {
            if(inters[i].start <= res[(*returnSize)-1][1]){
                res[(*returnSize)-1][1] = res[(*returnSize)-1][1] > inters[i].end ? res[(*returnSize)-1][1] : inters[i].end;
            } else {
                int *tmp = (int *)malloc(sizeof(int)*2);
                tmp[0] = inters[i].start;
                tmp[1] = inters[i].end;
                res[(*returnSize)] = tmp;
                (*returnColumnSizes)[(*returnSize)] = 2;
                (*returnSize)++;
            }
        }
    }
    return res;
}
// @lc code=end

