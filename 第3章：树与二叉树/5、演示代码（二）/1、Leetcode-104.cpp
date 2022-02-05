 
/*************************************************************************
   > File Name: 104.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  4/25 20:08:25 2019
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int d1 = maxDepth(root->left);
    int d2 = maxDepth(root->right);
    return fmax(d1, d2) + 1;
}