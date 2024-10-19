#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int m, n, i, j, flag = 0;
    scanf("%d", &n);
    int *army = (int *) malloc(n * sizeof(int)); //动态数组
    memset(army, 0, n * sizeof(int));
    int ans = n;
    while(ans > 3) {
        int ct = 0;
        for(i = 0;i < n;++i) {
            if(!army[i])++ct; //报数人数增加
            if(ct == 2 + flag) {
                ct = 0;
                --ans;
                army[i] = 1; //标记为已经找过
            }
            if(ans < 4)break;
        }
        flag = (flag + 1) % 2; //轮换 2 3 报数
    }
    for(i = 0;i < n;++i)if(!army[i])printf("%d ", i + 1);
    getchar();getchar();
    return 0;
}