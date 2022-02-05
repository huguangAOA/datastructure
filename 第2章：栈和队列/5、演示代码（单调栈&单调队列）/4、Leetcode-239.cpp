 
/*************************************************************************
   > File Name: 239.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  4/11 18:58:05 2019
 ************************************************************************/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int n = (numsSize == 0 ? 0 : numsSize - k + 1);
    int *ret = (int *)malloc(sizeof(int) * n);
    int *q = (int *)malloc(sizeof(int) * numsSize);
    int head = 0, tail = 0;
    *returnSize = n;
    n = 0;
    for (int i = 0; i < numsSize; i++) {
        while (tail - head && nums[i] > nums[q[tail - 1]]) --tail;
        q[tail++] = i;
        if (i - q[head] + 1 > k) head++;
        if (i + 1 >= k) ret[n++] = nums[q[head]];
    }
    free(q);
    return ret;
}