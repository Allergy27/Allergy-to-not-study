#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int m, n, tile = 0, x, size = 0, map[5270] = { 0 }; //map模拟哈希表
    scanf("%d%d", &m, &n);
    int *qwq = (int *) malloc(m * sizeof(int));
    memset(qwq, 0, m * sizeof(int));
    for(int i = 0;i < n;++i) {
        scanf("%d", &x)
        if(!map[x]) { //不在内存中
            map[qwq[tile]] = 0, qwq[tile] = x; //尾指针元素改为 x
            tile = (tile + 1) % m; //尾指针移动到下一位
            ++size, map[x] = 1; //计数并更新内存访问
        }
    }
    printf("%d", size);
    free(qwq);
    return 0;
}
