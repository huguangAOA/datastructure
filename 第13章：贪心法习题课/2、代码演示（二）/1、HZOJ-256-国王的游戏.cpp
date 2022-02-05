 
/*************************************************************************
   > File Name: 256.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  6/20 19:57:07 2019
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
#define MAX_N 1000
#define MAX_M 6000

struct Data {
    int a, b;
} arr[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
    return a.a * a.b < b.a * b.b;
}

void set(int *arr, int x) {
    arr[0] = 0;
    do {
        arr[0]++;
        arr[arr[0]] = x % 10;
        x /= 10;
    } while (x);
    return ;
}

void multiply(int *arr, int x) {
    for (int i = 1; i <= arr[0]; i++) arr[i] *= x;
    for (int i = 1; i <= arr[0]; i++) {
        if (arr[i] < 10) continue;
        arr[i + 1] += arr[i] / 10;
        arr[i] %= 10;
        arr[0] += (i == arr[0]);
        arr[arr[0] + 1] = 0;
    }
    return ;
}

void div(int *arr, int x, int *ret) {
    int i = arr[0], temp = 0;
    while (i && temp * 10 + arr[i] < x) temp = temp * 10 + arr[i--];
    if (i == 0) {
        set(ret, 0);
        return ;
    }
    ret[0] = i;
    while (i) {
        temp = temp * 10 + arr[i];
        ret[i--] = temp / x;
        temp %= x;
    }
    return ;
}

bool bigger_than(int *num1, int *num2) {
    if (num1[0] - num2[0]) return num1[0] > num2[0];
    for (int i = num1[0]; i >= 1; i--) {
        if (num1[i] - num2[i]) return num1[i] > num2[i];
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) cin >> arr[i].a >> arr[i].b;
    sort(arr + 1, arr + 1 + n, cmp);
    int p[MAX_M + 5], ans[MAX_M + 5], temp[MAX_M + 5]; 
    set(p, arr[0].a);
    set(ans, 0);
    for (int i = 1; i <= n; i++) {
        div(p, arr[i].b, temp);
        if (bigger_than(temp, ans)) memcpy(ans, temp, sizeof(temp));
        multiply(p, arr[i].a);
    }
    for (int i = ans[0]; i >= 1; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}