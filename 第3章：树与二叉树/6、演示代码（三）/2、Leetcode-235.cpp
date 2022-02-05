 
/*************************************************************************
   > File Name: 235.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  4/25 20:36:36 2019
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* __lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root->val == p->val) return p;
    if (root->val == q->val) return q;
    if (p->val < root->val && q->val > root->val) return root;
    if (p->val > root->val) return __lowestCommonAncestor(root->right, p, q);
    return __lowestCommonAncestor(root->left, p, q);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;
    if (p->val == q->val) return p;
    if (p->val > q->val) {
        struct TreeNode *temp = p;
        p = q;
        q = temp;
    }
    return __lowestCommonAncestor(root, p, q);
}