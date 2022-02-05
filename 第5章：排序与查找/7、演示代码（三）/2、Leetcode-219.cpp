 
/*************************************************************************
   > File Name: 219.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 六  5/11 16:07:27 2019
 ************************************************************************/

typedef struct Data {
    int val, cnt;
} Data;

typedef struct HashTable {
    Data *data;
    int *flag;
    int size;
} HashTable;

HashTable *init(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->data = (Data *)malloc(sizeof(Data) * n);
    h->flag = (int *)calloc(sizeof(int), (n / 31 + 1));
    h->size = n;
    return h;
}

int hash(int val) {
    return val & 0x7fffffff;
}

int check(HashTable *h, int ind) {
    int x = ind / 31, y = ind % 31;
    return h->flag[x] & (1 << y);
}

void set(HashTable *h, int ind, int val) {
    int x = ind / 31, y = ind % 31;
    h->flag[x] |= (1 << y);
    h->data[ind].val = val;
    h->data[ind].cnt = 0;
    return ;
}

void insert(HashTable *h, int val) {
    int ind = hash(val) % h->size;
    int times = 1;
    while (check(h, ind) && h->data[ind].val != val) {
        ind += (times * times);
        ind %= h->size;
    }
    if (check(h, ind)) return ;
    set(h, ind, val);
    return ;
}

int query(HashTable *h, int val) {
    int ind = hash(val) % h->size;
    int times = 1;
    while (check(h, ind) && h->data[ind].val != val) {
        ind += (times * times);
        ind %= h->size;
    }
    if (check(h, ind)) return ind;
    return -1;
}

int add_once(HashTable *h, int val, int delta) {
    int ind = query(h, val);
    if (ind == -1) return -1;
    h->data[ind].cnt += delta;
    return h->data[ind].cnt;
}

void clear(HashTable *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h->flag);
    free(h);
    return ;
}


bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    if (numsSize == 0 || k == 0) return false;
    HashTable *h = init(3 * numsSize);
    for (int i = 0; i < numsSize; i++) {
        insert(h, nums[i]);
    }
    int cnt = 0;
    k = fmin(k + 1, numsSize);
    for (int i = 0; i < k; i++) {
        cnt += (add_once(h, nums[i], 1) == 1);
    }
    if (cnt != k) return true;
    for (int i = k; i < numsSize; i++) {
        cnt += (add_once(h, nums[i], 1) == 1);
        cnt -= (add_once(h, nums[i - k], -1) == 0);
        if (cnt != k) return true;
    }
    clear(h);
    return false;
}