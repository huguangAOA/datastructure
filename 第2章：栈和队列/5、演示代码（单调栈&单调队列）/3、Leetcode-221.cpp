 
/*************************************************************************
   > File Name: 221.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  4/11 18:58:05 2019
 ************************************************************************/

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSizes) {
    int n = matrixRowSize, m = matrixColSizes;
    if (n == 0) return 0;
    int **cnt = (int **)malloc(sizeof(int *) * n);
    int *q = (int *)malloc(sizeof(int) * m);
    int head, tail, l;
    for (int i = 0; i < n; i++) cnt[i] = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) cnt[0][i] = (matrix[0][i] == '1');
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt[i][j] = (matrix[i][j] == '1' ? cnt[i - 1][j] + 1 : 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        head = tail = 0;
        l = 0;
        for (int j = 0; j < m; j++) {
            while (tail - head > 0 && cnt[i][q[tail - 1]] > cnt[i][j]) --tail;
            q[tail++] = j;       
            while (j - l >= 0 && j - l + 1 > cnt[i][q[head]]) {
                ++l;
                if (q[head] < l) ++head;
            }
            ans = fmax(ans, (j - l + 1) * (j - l + 1));    
        }
    }
    for (int i = 0; i < n; i++) free(cnt[i]);
    free(cnt);
    free(q);
    return ans;
}