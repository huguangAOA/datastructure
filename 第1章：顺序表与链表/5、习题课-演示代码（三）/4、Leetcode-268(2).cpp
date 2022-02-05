 
/*************************************************************************
   > File Name: 268-2.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 一  7/15 16:45:45 2019
 ************************************************************************/

int missingNumber(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] != i && nums[i] != numsSize) {
            int a = nums[i], b = nums[nums[i]];
            nums[a] = a, nums[i] = b;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] - i) return i;
    }
    return numsSize;
}