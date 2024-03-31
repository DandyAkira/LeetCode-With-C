/*
 * @lc app=leetcode.cn id=1551 lang=c
 *
 * [1551] 使数组中所有元素相等的最小操作数
 */

// @lc code=start

/*
    [1, 3, 5, 7, 9]
    长度为奇数，从中位数的左右两侧第一个数开始，各需要 2，4，6...次操作 k = n/2; 首项为2，末项为2k，共需要(2+2k)k/2=(k+1)k
    [1, 3, 5, 7]
    长度为偶数，从中间两位开始，各需要 1，3，5，7...次操作， k = n/2; 首项为1，末项为2k-1，k平方

*/

#include<stdio.h>
#include<stdlib.h>


int minOperations(int n){
    int t = n%2;
    int k = n/2;
    if(t!=0){
        return k*(k+1);
    } else {
        return k*k;
    }
}
// @lc code=end

