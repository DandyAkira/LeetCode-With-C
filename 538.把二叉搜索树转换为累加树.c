/*
 * @lc app=leetcode.cn id=538 lang=c
 *
 * [538] 把二叉搜索树转换为累加树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
*/

#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sum;

struct TreeNode* Inverse_Mid_Order(struct TreeNode* node){
    if(node != NULL){
        Inverse_Mid_Order(node->right);
        sum += node->val;
        node->val = sum;
        Inverse_Mid_Order(node->left);
    }
    return node;
}

struct TreeNode* convertBST(struct TreeNode* root){
    sum = 0;
    if(root != NULL){
        Inverse_Mid_Order(root->right);
        sum += root->val;
        root->val = sum;
        Inverse_Mid_Order(root->left);
    }
    return root;
}
// @lc code=end

