 
/*************************************************************************
   > File Name: 38.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 六  5/11 15:06:15 2019
 ************************************************************************/

char* countAndSay(int n) {
    if (n == 1) return strdup("1");
    char *s = countAndSay(n - 1);
    int len = 1;
    for (int i = 1; s[i]; i++) len += (s[i] != s[i - 1]);
    len = len << 1 + 1;
    char *ret = (char *)malloc(sizeof(char) * len);
    char ch = s[0];
    int cnt = 1, offset = 0;
    for (int i = 1; s[i]; i++) {
        if (s[i] == s[i - 1]) {
            cnt += 1;
        } else {
            offset += sprintf(ret + offset, "%d%c\0", cnt, ch);
            ch = s[i];
            cnt = 1;
        }
    }
    sprintf(ret + offset, "%d%c\0", cnt, ch);
    free(s);
    return ret;
}