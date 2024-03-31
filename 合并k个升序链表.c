#include<stdio.h>
#include<stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode {
    int val;
   struct ListNode *next;
};
typedef struct ListNode ListNode;

ListNode* FindMin(struct ListNode** lists, int listsSize) {
    ListNode *min = NULL;
    int index = -1;
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] == NULL) {
            continue;
        }
        if (min == NULL) {
            min = lists[i];
        }
        if (lists[i]->val <= min->val) {
            min = lists[i];
            index = i;
        }
    }
    if (index >= 0) {
        lists[index] = lists[index]->next;
    }
    return min;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) {
        return NULL;
    }
    ListNode *dummy = malloc(sizeof(ListNode));
    dummy->next = NULL;
    ListNode *anchor = dummy;
    ListNode *curMin = FindMin(lists, listsSize);
    while (curMin) {
        anchor->next = curMin;
        anchor = curMin;
        curMin = FindMin(lists, listsSize);
    }

    return dummy->next;
}