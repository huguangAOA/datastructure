 
/*************************************************************************
   > File Name: 268.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 一  7/15 16:27:08 2019
 ************************************************************************/

int missingNumber(int* nums, int numsSize){
    int ans = 0, n = numsSize + 1;
    for (int i = 0, j = 2; ; i += 1, j *= 2) {
        int cnt = n / j * (j >> 1);
        if (n % j > (j >> 1)) {
            cnt += n % j - (j >> 1);
        }
        if (cnt % 2) ans |= (1 << i);
        if (j >= n) break;
    }
    for (int i = 0; i < numsSize; i++) ans ^= nums[i];
    return ans;
}