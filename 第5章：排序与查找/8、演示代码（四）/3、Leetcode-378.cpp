 
/*************************************************************************
   > File Name: 378.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 六  5/11 18:55:45 2019
 ************************************************************************/

typedef struct Data {
    int cnt, rank;
} Data;

Data count(int **matrix, int n, int m, int x) {
    int i = n, j = 0, rank = 0, cnt = 0, k;
    for (int j = 0; j < m; j++) {
        while (i > 0 && matrix[i - 1][j] > x) --i;
        rank += i;
        k = i - 1;
        while (k >= 0 && matrix[k][j] == x) --k, ++cnt;
    }
    Data d = {cnt, rank};
    return d;
}

int kthSmallest(int** matrix, int matrixRowSize, int *matrixColSize, int k) {
    int n = matrixRowSize, m = matrixRowSize;
    int head = matrix[0][0], tail = matrix[n - 1][m - 1], mid;

    while (head <= tail) {
        mid = head + ((tail - head) >> 1);
        Data d = count(matrix, n, m, mid);
        if (k <= d.rank && k >= d.rank - d.cnt + 1) {
            return mid;
        }
        if (d.rank < k) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}