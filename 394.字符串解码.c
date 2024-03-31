/*
 * @lc app=leetcode.cn id=394 lang=c
 *
 * [394] 字符串解码
 */

// @lc code=start
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_VAL 50000

char charStack[MAX_VAL];
int numStack[MAX_VAL];
int top = -1;
int numtop = -1;

void PushChar(char ch){
    if(top == MAX_VAL-1){
        printf("Stack Overflow\n");
        return;
    }
    charStack[++top] = ch;
}

char PopChar(){
    if(top == -1){
        printf("Stack Empty");
        return '0';
    }
    return charStack[top--];
}

char PeekChar(){
    if(top == -1){
        printf("Stack Empty");
        return '0';
    }
    return charStack[top];
}

void PushInt(int val){
    if(numtop == MAX_VAL-1){
        printf("Num Stack overflow\n");
        return;
    }
    numStack[++numtop] = val;
}

int PopInt(){
    if(numtop == -1){
        printf("Num Stack Empty\n");
        return 0;
    }
    return numStack[numtop--];
}

int PeekInt(){
        if(numtop == -1){
        printf("Num Stack Empty\n");
        return 0;
    }
    return numStack[numtop];
}

void Multiply(){
    int times = PopInt();
    int k = top;
    while(charStack[k] != '[') k--;
    int poplen = top - k;
    k = 0;
    char pops[poplen];
    while(PeekChar() != '['){
        pops[k++] = PopChar();
    }
    PopChar();
    for(int i=0; i<times; i++){
        for(int j=k-1; j>=0; j--){
            PushChar(pops[j]);
        }
    }
}

char * decodeString(char * str){
    int len = strlen(str);
    int num = 0;
    for(int j=0; j<len; j++){
        if(str[j] >= '0' && str[j] <= '9'){
            num = num*10 + (str[j]-'0');
        } else {
            if(str[j] == '['){
                PushInt(num);
                num = 0;
            }
            if(str[j] != ']'){
                PushChar(str[j]);
            } else {
                Multiply();
            }
        }
    }

    int length = top+1;
    char *res = (char *)malloc(sizeof(char)*(length+1));
    res[length] = '\0';
    for(int j=length-1; j>=0; j--){
        res[j] = PopChar();
    }
    return res;
}
// @lc code=end

