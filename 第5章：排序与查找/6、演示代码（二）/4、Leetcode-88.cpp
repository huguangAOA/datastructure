 
/*************************************************************************
   > File Name: 88.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 六  5/11 15:14:22 2019
 ************************************************************************/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int p = m, q = n, t = m + n;
    while (p || q) {
        if (q == 0 || (p && nums1[p - 1] >= nums2[q - 1])) {
            nums1[--t] = nums1[--p];
        } else {
            nums1[--t] = nums2[--q];
        }
    }
    return ;
}