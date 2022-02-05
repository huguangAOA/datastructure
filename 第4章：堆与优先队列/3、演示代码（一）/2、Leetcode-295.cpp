 
/*************************************************************************
   > File Name: 295.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 六  4/27 21:20:04 2019
 ************************************************************************/



typedef struct Heap {
    int *data;
    int n, size;
} Heap;

void expandHeap(Heap *h) {
    h->data = realloc(h->data, 2 * h->size * sizeof(int));
    h->size *= 2;
    return ;
}

#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}

#define pushHeap(h, val, comp) { \
    if (h->size == h->n + 1) { \
        expandHeap(h); \
    } \
    h->data[++(h->n)] = val; \
    int ind = h->n; \
    while (ind != 1 && h->data[ind] comp h->data[ind >> 1]) { \
        swap(h->data[ind], h->data[ind >> 1]); \
        ind >>= 1; \
    } \
}

#define popHeap(h, comp) do { \
    if (h->n == 0) break; \
    h->data[1] = h->data[(h->n)--]; \
    int ind = 1; \
    while (ind << 1 <= h->n) { \
        int temp = ind, l = ind << 1, r = ind << 1 | 1; \
        if (h->data[l] comp h->data[temp]) temp = l; \
        if (r <= h->n && h->data[r] comp h->data[temp]) temp = r; \
        if (temp == ind) break; \
        swap(h->data[temp], h->data[ind]); \
        ind = temp; \
    } \
} while(0);

Heap *creatHeap() {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->size = 100;
    h->data = (int *)malloc(sizeof(int) * h->size);
    h->n = 0;
    return h;
}

void clearHeap(Heap *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h);
    return ;
}

typedef struct {
    Heap *min_heap, *max_heap;
} MedianFinder;

/** initialize your data structure here. */

MedianFinder* medianFinderCreate() {
    MedianFinder* m = (MedianFinder*)malloc(sizeof(MedianFinder));
    m->min_heap = creatHeap();
    m->max_heap = creatHeap();
    return m;
}

void medianFinderAddNum(MedianFinder* m, int num) {
    if (m->min_heap->n == 0 || num >= m->min_heap->data[1]) {
        pushHeap(m->min_heap, num, <);
    } else {
        pushHeap(m->max_heap, num, >);
    }
    if (m->min_heap->n - m->max_heap->n == 2) {
        pushHeap(m->max_heap, m->min_heap->data[1], >);
        popHeap(m->min_heap, <);
    }
    if (m->max_heap->n - m->min_heap->n == 2) {
        pushHeap(m->min_heap, m->max_heap->data[1], <);
        popHeap(m->max_heap, >);
    }
    return ;
}

double medianFinderFindMedian(MedianFinder* m) {
    switch (m->min_heap->n - m->max_heap->n) {
        case -1: return m->max_heap->data[1];
        case 0: return 1.0 * (m->min_heap->data[1] + m->max_heap->data[1]) / 2.0;
        case 1: return m->min_heap->data[1];
    }
    return 0.0;
}

void medianFinderFree(MedianFinder* obj) {
    if (obj == NULL) return ;
    clearHeap(obj->min_heap);
    clearHeap(obj->max_heap);
    free(obj);
    return ;
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);

 * double param_2 = medianFinderFindMedian(obj);

 * medianFinderFree(obj);
*/