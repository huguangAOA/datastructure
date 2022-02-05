 
/*************************************************************************
   > File Name: 111.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  4/25 20:23:14 2019
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->left == NULL || root->right == NULL)
        return minDepth(root->right ? root->right : root->left) + 1;
    return fmin(minDepth(root->left), minDepth(root->right)) + 1;
}