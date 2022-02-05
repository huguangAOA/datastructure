 
/*************************************************************************
   > File Name: 2-2.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  5/ 9 20:46:07 2019
 ************************************************************************/

int lengthOfLongestSubstring(char* s) {
    int ind[128], l = 0, ans = 0;
    memset(ind, -1, sizeof(ind));
    for (int i = 0; s[i]; i++) {
        l += 1;
        if (i - ind[s[i]] < l) l = i - ind[s[i]];
        ind[s[i]] = i;
        if (l > ans) ans = l;
    }
    return ans;
}