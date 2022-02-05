 
/*************************************************************************
   > File Name: 1-2.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  5/ 9 19:59:26 2019
 ************************************************************************/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct Data {
    int val, ind;
} Data;

typedef struct HashTable {
    Data *data;
    int *flag;
    int size;
} HashTable;

HashTable *init(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->data = (Data *)malloc(sizeof(Data) * n);
    h->size = n;
    h->flag = (int *)calloc(sizeof(int), (n / 32 + 1));
    return h;
}

int hash(int val) {
    return val & 0x7fffffff;
}

int check(HashTable *h, int ind) {
    int x = ind / 32, y = ind % 32;
    return (h->flag[x] & (1LL << y)) != 0;
}

void set(HashTable *h, int ind, Data d) {
    int x = ind / 32, y = ind % 32;
    h->data[ind] = d;
    h->flag[x] |= (1LL << y);
    return ;
}

void insert(HashTable *h, int val, int val_ind) {
    Data d = {val, val_ind};
    int ind = hash(val) % h->size;
    int time = 1;
    while (check(h, ind)) {
        ind += (time * time);
        ind %= h->size;
    }
    set(h, ind, d);
    return ;
}

int query(HashTable *h, int val) {
    int ind = hash(val) % h->size;
    int time = 1;
    while (check(h, ind) && h->data[ind].val != val) {
        ind += (time * time);
        ind %= h->size;
    }
    if (check(h, ind)) return h->data[ind].ind;
    return -1;
}

void clear(HashTable *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h->flag);
    free(h);
    return ;
}

int* twoSum(int* nums, int numsSize, int target, int *returnSize) {
    HashTable *h = init(numsSize * 3);
    int *ret = (int *)malloc(sizeof(int) * 2);
    for (int i = 0, ind; i < numsSize; i++) {
        if ((ind = query(h, target - nums[i])) == -1) {
            insert(h, nums[i], i);
            continue;
        }
        ret[0] = ind;
        ret[1] = i;
        break;
    }
    returnSize[0] = 2;
    return ret;
}