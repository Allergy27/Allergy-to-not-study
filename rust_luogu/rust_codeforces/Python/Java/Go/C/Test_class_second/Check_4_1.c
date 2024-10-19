#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int n, k, limit = 1, dp[100001] = { 0 };
    scanf("%d%d", &n, &k);
    while((n << limit) < k)++limit; //计算最大可能值为n*2的多少次方
    limit = n << limit; //重新计算最大可能值
    for(int i = n;i > n / 2 + 1;--i)dp[i] = n - i + 1; //先往左转移
    for(int i = n;i <= limit;++i) { //从左往右转移
        if(i % 2)dp[i] = dp[i - 1] + 1;
        //偶数可以是从前一个转移，也可以由 i/2 转移
        else dp[i] = (dp[i - 1] > dp[i / 2] ? dp[i / 2] : dp[i - 1]) + 1;
    }
    for(int i = limit - 1;i >= k;--i) //从右往左转移
        dp[i] = dp[i] > (dp[i + 1] + 1) ? dp[i + 1] + 1 : dp[i];
    printf("%d", dp[k]);
    return 0;
}
