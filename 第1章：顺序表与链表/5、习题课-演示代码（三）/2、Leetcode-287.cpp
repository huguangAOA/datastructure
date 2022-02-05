 
/*************************************************************************
   > File Name: 287.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 一  7/15 15:58:54 2019
 ************************************************************************/

int findDuplicate(int* nums, int numsSize){
    int p = nums[0], q = nums[0];
    do {
        p = nums[p];
        q = nums[nums[q]];
    } while (p != q);
    q = nums[0];
    while (p != q) {
        p = nums[p];
        q = nums[q];
    }
    return p;
}