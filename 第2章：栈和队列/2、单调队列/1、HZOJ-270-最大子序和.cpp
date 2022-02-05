 
/*************************************************************************
   > File Name: 270.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 三  7/17 15:47:49 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 300000
int q[MAX_N + 5], head, tail;
long long arr[MAX_N + 5];

int main() {
    long long n, m, ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i], arr[i] += arr[i - 1];
    head = tail = 0;
    q[tail++] = 0;
    ans = arr[1];
    for (int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] - arr[q[head]]);
        while (tail - head && arr[q[tail - 1]] >= arr[i]) tail--;
        q[tail++] = i;
        if (q[head] == i - m) head++;
    }
    cout << ans << endl;
    return 0;
}