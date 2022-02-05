 
/*************************************************************************
   > File Name: 10.string.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 五  8/16 18:13:38 2019
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
#define TEST(func, a, b) { \
    printf("TEST %s(%s, %s) = %d\n", #func, a, b, func(a, b)); \
}
char text[MAX_N + 5], pattern[MAX_N + 5];

int brute_force(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    for (int i = 0, I = len1 - len2 + 1; i < I; i++) {
        int j = 0;
        for (; t[j]; j++) {
            if (t[j] == s[i + j]) continue;
            break;
        }
        if (!t[j]) return i;
    }
    return -1;
}

int sunday(char *s, char *t) {
    int ind[128] = {0};
    int len1 = strlen(s);
    int len2 = strlen(t);
    for (int i = 0; i < 128; i++) ind[i] = len2 + 1;
    for (int i = 0; t[i]; i++) ind[t[i]] = len2 - i;
    for (int i = 0, I = len1 - len2 + 1; i < I;) {
        int flag = 1;
        for (int j = 0; j < len2; j++) {
            if (t[j] == s[i + j]) continue;
            i += ind[s[i + len2]];
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}

int shift_and(char *s, char *t) {
    int code[128] = {0};
    int len = 0;
    for (len = 0; t[len]; len++) {
        code[t[len]] |= (1 << len);
    }
    int p = 0;
    for (int i = 0; s[i]; i++) {
        p = (p << 1 | 1) & code[s[i]];
        if (p & (1 << (len - 1))) return i - len + 1;
    }
    return -1;
}

int kmp(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    int *next = (int *)malloc(sizeof(int) * len2);
    next[0] = -1;
    for (int i = 1, j = -1; i < len2; i++) {
        while (j != -1 && t[j + 1] != t[i]) j = next[j];
        if (t[j + 1] == t[i]) j += 1;
        next[i] = j;
    }
    for (int i = 0, j = -1; s[i]; i++) {
        while (j != -1 && t[j + 1] != s[i]) j = next[j];
        if (t[j + 1] == s[i]) j += 1;
        if (t[j + 1] == 0) return i - len2 + 1;
    }
    free(next);
    return -1;
}

int main() {
    scanf("%s%s", text, pattern);
    TEST(brute_force, text, pattern);
    TEST(kmp, text, pattern);
    TEST(sunday, text, pattern);
    TEST(shift_and, text, pattern);
    return 0;
}