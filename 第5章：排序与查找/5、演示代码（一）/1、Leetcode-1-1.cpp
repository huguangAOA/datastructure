 
/*************************************************************************
   > File Name: 1-1.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  5/ 9 19:59:26 2019
 ************************************************************************/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void radix_sort(int *arr, int *main_ind, int n) {
    #define MAX_N 65536
    #define MAX_M 32768
    #define L(x) (x & 0xffff)
    #define H(x) ((x >> 16) & 0xffff)
    int cnt[MAX_N] = {0}, *p;
    int *temp = (int *)malloc(sizeof(int) * n);
    int *ind = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) cnt[L(arr[i])] += 1;
    for (int i = 1 ; i < MAX_N; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        temp[--(cnt[L(arr[i])])] = arr[i];
        ind[cnt[L(arr[i])]] = i;
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) cnt[H(temp[i])] += 1;
    for (int i = MAX_M; i < MAX_M + MAX_N; i++) cnt[i % MAX_N] += cnt[(i - 1) % MAX_N];
    for (int i = n - 1; i >= 0; i--) {
        arr[--(cnt[H(temp[i])])] = temp[i];
        main_ind[cnt[H(temp[i])]] = ind[i];
    }
    free(temp);
    free(ind);
    return ;
}

int* twoSum(int* nums, int numsSize, int target, int *returnSize) {
    int *ind = (int *)malloc(sizeof(int) * numsSize);
    radix_sort(nums, ind, numsSize);
    int p = 0, q = numsSize - 1;
    while (nums[p] + nums[q] != target) {
        if (nums[p] + nums[q] > target) --q;
        else ++p;
    }
    int *ret = (int *)malloc(sizeof(int) * 2);
    ret[0] = ind[p];
    ret[1] = ind[q];
    if (ret[0] > ret[1]) {
        ret[0] ^= ret[1], ret[1] ^= ret[0], ret[0] ^= ret[1];
    }
    free(ind);
    returnSize[0] = 2;
    return ret;
}