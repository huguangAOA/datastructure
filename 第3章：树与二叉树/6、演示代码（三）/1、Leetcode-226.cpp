 
/*************************************************************************
   > File Name: 226.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  4/25 20:25:59 2019
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left), invertTree(root->right);
    return root;
}