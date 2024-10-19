#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int m, n, i, j = 0, max = 0;
    scanf("%d", &n);
    int *a = (int *) malloc(n * sizeof(int)); //题目没给出数据范围，采用动态数组
    int *b = (int *) malloc(n * sizeof(int));

    for(i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(max <= a[i])max = a[i] + 1; //确定一个尽可能大的边界
    }

    int *map = (int *) malloc(max * sizeof(int)); //模拟set集合
    memset(map, 0, max * sizeof(int)); //清0

    for(i = 0; i < n; ++i)
        if(!map[a[i]])b[j++] = a[i], map[a[i]] = 1; //提纯，标记集合中已出现数字

    for(i = 0; i < j; ++i)printf("%d ", b[i]);
    free(map);
    free(a);
    free(b);
    getchar();getchar();
    return 0;
}
