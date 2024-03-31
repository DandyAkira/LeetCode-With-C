#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}treenode;

typedef struct ListNode {
    int val;
    struct ListNode *next;
}listnode;

typedef struct List {
    struct ListNode *head;
    struct ListNode *tail;
    struct List *next;
    struct List *prev;
    int size;
}list;

typedef struct ArrayNode{
    int *array;
    struct ArrayNode *next;
    int size;
}arraynode;

void dfs(treenode* node, list* lst){
    if(node != NULL){

        listnode *lsn = malloc(sizeof(listnode));
        lsn->val = node->val;
        lsn->next = NULL;
        
        lst->tail->next = lsn;
        lst->tail = lsn;

        lst->size++;

        if(node->left != NULL) {
            if(lst->prev == NULL) {
                list *prevlist = malloc(sizeof(list));
                prevlist->next = lst;
                lst->prev = prevlist;
            }
            dfs(node->left, lst->prev);
        }

        if(node->right != NULL){
            if(lst->next == NULL) {
                list *nextlist = malloc(sizeof(list));
                nextlist->prev = lst;
                lst->next =nextlist;
            }
            dfs(node->right, lst->next);
        }
        
    }
}

/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/

int** verticalOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    treenode *p = root;
    list *lst = malloc(sizeof(list));
    dfs(root, lst);
    while(lst->prev != NULL){
        lst = lst->prev;
    }
    arraynode *arrayhead = malloc(sizeof(arraynode));
    arraynode *curarray = arrayhead;
    while(lst!=NULL){
        int arr[lst->size];
        listnode *num = lst->head->next;
        int i=0;
        while(num != NULL){
            arr[i] = num->val;
            i++;
            num = num->next;
        }
        arraynode *cur = malloc(sizeof(arraynode));
        cur->array = &arr;
        curarray->next = cur;
        curarray = cur;
        arrayhead->size++;
    }
    int* ret[arrayhead->size] = malloc(sizeof(int) * 999);
    for(int i=0; i<arrayhead->size; i++){
        ret[i] = arrayhead->next->array;
        arrayhead = arrayhead->next;
    }
    return ret;
}

int main(void){
    treenode *a = malloc(sizeof(treenode));
    return 0;
}