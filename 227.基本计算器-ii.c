/*
 * @lc app=leetcode.cn id=227 lang=c
 *
 * [227] 基本计算器 II
 */

// @lc code=start

#include<stdio.h>
#include<stdlib.h>

#define MAX_VAL 2000

typedef struct CharStack
{
    char stack[MAX_VAL];
    int top;
} charstack;


typedef struct IntStack
{
    int stack[MAX_VAL];
    int top;
} intstack;

char PopChar(charstack *stk){
    if(stk->top < 0){
        printf("Stack Empty\n");
        return '0';
    }
    return stk->stack[(stk->top)--];
}

char PeekChar(charstack *stk){
    if(stk->top < 0){
        printf("Stack Empty\n");
        return '0';
    }
    return stk->stack[stk->top];
}

void PushChar(charstack *stk, char ch){
    if(stk->top == MAX_VAL-1){
        printf("Stack Full\n");
        return;
    }
    stk->stack[++(stk->top)] = ch;
}

void ClearChar(charstack *stk){
    while(stk->top > -1){
        Pop(stk);
    }
}

int PopInt(intstack *stk){
    if(stk->top < 0){
        printf("Stack Empty\n");
        return '0';
    }
    return stk->stack[(stk->top)--];
}

int PeekInt(intstack *stk){
    if(stk->top < 0){
        printf("Stack Empty\n");
        return '0';
    }
    return stk->stack[stk->top];
}

void PushInt(intstack *stk, char ch){
    if(stk->top == MAX_VAL-1){
        printf("Stack Full\n");
        return;
    }
    stk->stack[++(stk->top)] = ch;
}

void ClearInt(intstack *stk){
    while(stk->top > -1){
        Pop(stk);
    }
}

int plainCal(){

}

int calculate(char * s){
    intstack *numstack = (intstack *)malloc(sizeof(intstack));
    numstack->top = -1;
    charstack *signstack = (charstack *)malloc(sizeof(charstack));
    signstack->top = -1;
    int i=0;
    while(s[i] != '\0'){
        if(s[i] == ' '){
            i++;
            continue;
        }
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            PushChar(signstack, s[i]);
            continue;
        }
        if(s[i] == '('){
            PushChar(signstack, s[i]);
            
        }
    }

}
// @lc code=end

int main(int argc, char const *argv[])
{
    charstack *a = (charstack *)malloc(sizeof(charstack));
    a->top = -1;
    PushChar(a, 'x');

    return 0;
}
