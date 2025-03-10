// Copyright Allergy

#include <bits/stdc++.h>
#define maxN 15
int Broad[maxN], ES[maxN * 2], WN[2 * maxN + 1], UN[maxN], sum = 0;

int main() {
    int n;
    scanf("%d", &n);
    void dfs(int, int);
    dfs(0, n);

    std::vector<int> stk;

    printf("%d", sum);
    return 0;
}

void dfs(int i, int N) {  // i -> 行数
    for (int j = 0; j < N; ++j) {
        if ((!Broad[j]) && (!ES[i - j + N - 1]) && (!WN[i + j])) {
            // 输出路径
            UN[i] = j + 1;

            // 放置
            Broad[j] = 1;
            ES[i - j + N - 1] = 1;
            WN[i + j] = 1;
            if (i == N - 1) {  // 终点不再搜索
                ++sum;
                if (sum <= 3) {
                    for (int t = 0; t < N; ++t) printf("%d ", UN[t]);
                    printf("\n");
                }
            } else {
                // 往下搜
                dfs(i + 1, N);
            }
            // 回溯
            Broad[j] = 0;
            ES[i - j + N - 1] = 0;
            WN[i + j] = 0;
        }
    }
}