 
/*************************************************************************
   > File Name: 42.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 三  7/17 20:47:11 2019
 ************************************************************************/

int trap(int* height, int heightSize) {
    int n = heightSize, ans = 0, top = -1;
    int *stack = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < heightSize; i++) {
        while (top != -1 && height[stack[top]] <= height[i]) {
            if (top >= 1) {
                int w = i - stack[top - 1] - 1;
                int val1 = height[i] - height[stack[top]];
                int val2 = height[stack[top - 1]] - height[stack[top]];
                int h = (val1 < val2 ? val1 : val2);
                ans += h * w;
            }
            top--;
        }
        stack[++top] = i;
    }
    free(stack);
    return ans;
}