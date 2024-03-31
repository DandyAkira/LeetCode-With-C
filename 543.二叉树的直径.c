/*
 * @lc app=leetcode.cn id=543 lang=c
 *
 * [543] 二叉树的直径
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

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int depth(struct TreeNode* node){
    int res = -1;
    if(node != NULL){
        int left = depth(node->left) + 1;
        int right = depth(node->right) + 1;
        res = left > res ? left : res;
        res = right > res ? right : res;
    }
    return res;
}

int diameterOfBinaryTree_try(struct TreeNode* root){
    int res = 0;
    if(root != NULL){
        res = depth(root->left) + depth(root->right) + 2;
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        res = res > left ? res : left;
        res = res > right ? res : right;
    }
    return res;
}

// @lc code=end

