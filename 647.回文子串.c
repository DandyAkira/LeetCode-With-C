/*
 * @lc app=leetcode.cn id=647 lang=c
 *
 * [647] 回文子串
 */

// @lc code=start

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int countSubstrings(char * s){
    int res = 0;
    int length = strlen(s);

    //单个起步
    for (int i = 0; i < length; i++)
    {
        int x=i, y=i;
        while (x>=0 && y<length)
        {
            if(s[x] == s[y]){
                res++;
                x--;
                y++;
            } else {
                break;
            }
        }

        x = i; y = i+1;
        while (x>=0 && y<length)
        {
            if(s[x] == s[y]){
                res++;
                x--;
                y++;
            } else {
                break;
            }
        }
    }
    return res;
}
// @lc code=end

