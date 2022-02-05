 
/*************************************************************************
   > File Name: 703.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 五  8/ 9 20:38:12 2019
 ************************************************************************/

#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}

typedef struct {
    int *data;
    int cnt, size;
} KthLargest;

void downUpdate(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] < arr[temp]) temp = l;
        if (r <= n && arr[r] < arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return ;
}

void upUpdate(int *arr, int ind) {
    while (ind >> 1) {
        if (arr[ind] >= arr[ind >> 1]) break;
        swap(arr[ind], arr[ind >> 1]);
        ind >>= 1;
    }
    return ;
}

int kthLargestAdd(KthLargest*, int);
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *p = (KthLargest *)malloc(sizeof(KthLargest));
    p->data = (int *)malloc(sizeof(int) * (k + 1));
    p->size = k;
    p->cnt = k - 1;
    memcpy(p->data + 1, nums, sizeof(int) * (k - 1));
    for (int i = (k - 1) >> 1; i >= 1; --i) {
        downUpdate(p->data, k - 1, i);
    }
    for (int i = k - 1; i < numsSize; i++) {
        kthLargestAdd(p, nums[i]);
    }
    return p;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->cnt == obj->size) {
        if (val > obj->data[1]) {
            obj->data[1] = val;
            downUpdate(obj->data, obj->size, 1);
        }
    } else {
        obj->cnt += 1;
        obj->data[obj->cnt] = val;
        upUpdate(obj->data, obj->cnt);
    }
    return obj->data[1];
}

void kthLargestFree(KthLargest* obj) {
    if (obj == NULL) return ;
    free(obj->data);
    free(obj);
    return ;
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/