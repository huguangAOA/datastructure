 
/*************************************************************************
   > File Name: 237.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 一  7/15 19:11:25 2019
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *p = node->next;
    node->val = p->val;
    node->next = p->next;
    free(p);
    return ;
}