#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MOD 12007

int hashmul(int x[]) {
    int ans = x[0];
    for(int i = 1;i < 6;++i)ans = (ans * x[i]) % MOD;
    return ans;
}
int hashsum(int x[]) {
    return (x[0] + x[1] + x[2] + x[3] + x[4] + x[5]) % MOD;
}
int snow[MOD + 27][MOD + 27]; //模拟散列表
int main() {
    int n, flag = 1;
    scanf("%d", &n);
    for(int i = 0;flag && i < n;++i) {
        int x[6];
        scanf("%d%d%d%d%d%d,", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5]);
        if(snow[hashmul(x)][hashsum(x)]++)flag = 0;
    }
    if(!flag)printf("Twin snowflakes found\n");
    else printf("No two snowflakes found\n");
    return 0;
}
