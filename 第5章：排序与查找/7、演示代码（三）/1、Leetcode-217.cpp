 
/*************************************************************************
   > File Name: 217.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 六  5/11 15:26:13 2019
 ************************************************************************/

typedef struct HashTable {
    int *data;
    int *flag;
    int size;
} HashTable;

HashTable *init(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->data = (int *)malloc(sizeof(int) * n);
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
    h->data[ind] = val;
    return ;
}

void insert(HashTable *h, int val) {
    int ind = hash(val) % h->size;
    int times = 1;
    while (check(h, ind)) {
        ind += (times * times);
        ind %= h->size;
    }
    set(h, ind, val);
    return ;
}

int query(HashTable *h, int val) {
    int ind = hash(val) % h->size;
    int times = 1;
    while (check(h, ind) && h->data[ind] != val) {
        ind += (times * times);
        ind %= h->size;
    }
    return check(h, ind);
}

void clear(HashTable *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h->flag);
    free(h);
    return ;
}

bool containsDuplicate(int* nums, int numsSize){
    HashTable *h = init(numsSize * 3);
    for (int i = 0; i < numsSize; i++) {
        if (query(h, nums[i])) {
            clear(h);
            return true;
        }
        insert(h, nums[i]);
    }
    clear(h);
    return false;
}