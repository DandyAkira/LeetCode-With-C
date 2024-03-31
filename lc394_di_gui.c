/*
 * @lc app=leetcode.cn id=394 lang=c
 *
 * [394] 字符串解码
 */

// @lc code=start
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct CharNode {
    char ch;
    struct CharNode *next;
};

typedef struct CharQueue {
    struct CharNode *head;
    struct CharNode *tail;
    int size; 
} charqueue;

void EnQueue(charqueue *queue, char c){
    struct CharNode one;
    one.ch = c;
    one.next = NULL;
    queue->tail->next = &one;
    queue->tail = &one;
    queue->size++;
}

char DeQueue(charqueue *queue){
    if(queue->size < 1){
        return '\0';
    }
    printf("%c", queue->head->next->ch);
    struct CharNode *p = queue->head->next;
    char ret = p->ch;
    queue->head->next = p->next;
    free(p);

    queue->size--;
    return ret;
}

void Decode(char *str, int s, int e, charqueue *queue, int times){
    printf("%d, %d\n", s, e);
    for(int i=0; i<times; i++){
        int index = s;
        while(index<=e){
            if(str[index] > '0' && str[index] <= '9'){
                int ntimes = (int)(str[index] - '0');
                int ns = index+2;
                while(str[index] != ']') index++;
                int ne = index-1;
                Decode(str, ns, ne, queue, ntimes);
                index++;
            } else {
                EnQueue(queue, str[index]);
                printf("%c", queue->tail->ch);
                index++;
            }
        }
        
    }
}

char * decodeString(char * str){
    charqueue *queue = (charqueue *)malloc(sizeof(charqueue));
    queue->size=0;
    queue->tail=queue->head;
    Decode(str, 0, strlen(str)-1, queue, 1);
    printf("size = %d\n", queue->size);
    char *res = (char *)malloc(sizeof(char));
    res[queue->size] = '\0';
    int i = 0;
    struct CharNode *p = queue->head->next;
    while(p != NULL){
        res[i] = p->ch;
        p = p->next;
        printf("%c", res[i]);
        i++;
    }
    return res;
}
// @lc code=end

int main(int argc, char const *argv[])
{
    char *str = "3[a]2[bc]";
    printf("%s\n", decodeString(str));
    return 0;
}
