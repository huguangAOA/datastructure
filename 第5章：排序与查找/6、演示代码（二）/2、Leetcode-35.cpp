 
/*************************************************************************
   > File Name: 35.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 六  5/11 14:53:25 2019
 ************************************************************************/

int searchInsert(int* nums, int numsSize, int target){
    int head = 0, tail = numsSize, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (nums[mid] >= target) tail = mid;
        else head = mid + 1;
    }
    return head;
}