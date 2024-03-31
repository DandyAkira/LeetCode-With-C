/*
 * @lc app=leetcode.cn id=838 lang=c
 *
 * [838] 推多米诺
 */

// @lc code=start
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * pushDominoes(char * dominoes){
    int len = strlen(dominoes);
    char *Rstr = (char *)malloc(sizeof(char) * (len + 1));
    strcpy(Rstr, dominoes);
    Rstr[len] = '\0';
    char *Lstr = (char *)malloc(sizeof(char) * (len + 1));
    strcpy(Lstr, dominoes);
    Lstr[len] = '\0';

    for(int i=1; i<len; i++){
        if(Rstr[i-1] == 'R' && Rstr[i] != 'L')  Rstr[i] = 'R';
    }

    for(int i = (len-2); i>=0; i--){
        if(Lstr[i+1] == 'L' && Lstr[i] != 'R') Lstr[i] = 'L';
    }

    int pivetL = -1;
    int pivetR = len;

    for(int i = 0; i < len; i++){
        if(Rstr[i] == Lstr[i]){
            dominoes[i] = Rstr[i];
            if(Rstr[i] == 'R') pivetR = i;
        }
        else{
            if(Rstr[i] == 'R' && Lstr[i] == '.') dominoes[i] = 'R';
            if(Rstr[i] == '.' && Lstr[i] == 'L') dominoes[i] = 'L';
            if(Rstr[i] == 'R' && Lstr[i] == 'L'){
                if(pivetL < i){
                    pivetL = i;
                    while(Rstr[pivetL] != 'L') pivetL++;
                }
                if((i-pivetR) < (pivetL-i)) dominoes[i] = 'R';
                if((i-pivetR) > (pivetL-i)) dominoes[i] = 'L';
                if((i-pivetL) == (i-pivetR)) dominoes[i] = '.';
            }
        }
    }
    return dominoes;
}

// @lc code=end

