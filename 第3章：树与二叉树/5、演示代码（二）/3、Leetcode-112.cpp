 
/*************************************************************************
   > File Name: 112.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  4/25 20:19:13 2019
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL) return false;
    if (root->left == 0 && root->right == NULL) return root->val == sum;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}