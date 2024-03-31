/*
 * @lc app=leetcode.cn id=671 lang=c
 *
 * [671] 二叉树中第二小的节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include<stdlib.h>
#include<stdio.h>

void dfs(struct TreeNode* root, struct TreeNode* node, int *ans){
    if(node != NULL){
        if(node->val > root->val){
            if(*ans== -1) {*ans = node->val;}
            *ans = (*ans) < node->val ? (*ans) : node->val;
        }
        dfs(root, node->left, ans);
        dfs(root, node->right, ans);
    }
}



int findSecondMinimumValue(struct TreeNode* root){
    int *ans = (int *)malloc(sizeof(int));
    *ans = -1;
    if(root == NULL || root->left == NULL || root->right == NULL){
        return *ans;
    }
    dfs(root, root, ans);
    return *ans;
}
// @lc code=end

