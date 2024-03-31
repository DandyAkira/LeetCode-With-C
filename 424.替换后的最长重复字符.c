/*
 * @lc app=leetcode.cn id=424 lang=c
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int characterReplacement(char * s, int k){
    int len = strlen(s);
    int l=0, r=0;
    int res[26];
    memset(res, 0, sizeof(res));
    int max = 0;
    int x=0;
    char c;
    for(int i=0; i<26; i++){
        l=0; r=0; x=0;
        c = 'A' + i;
        while (r<len)
        {
            if(s[r] != c){
                x++;
                while (x>k)
                {
                    if(s[l] != c){
                        x--;
                    }
                    l++;
                }
            }
            r++;
            res[i] = fmax(res[i], r-l); 
        }
        max = fmax(max, res[i]);
    }
    return max;
}
// @lc code=end
int main(int argc, char const *argv[])
{
    char *s = "AABBA";
    printf("%s\n", characterReplacement(s, 2));
    return 0;
}


