// CopyRight Allergy
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
const int N = 20;
using namespace std;  // NOLINT
int n, m, x, cost, ans = 1000000;
int g[N][N];
int used[N];  // 1不要 2要
int c[N];

int check() {
    for (int i = 2; i <= m + 1; i++) {
        if (c[i] < x) return 0;
    }
    return 1;
}

void dsf(int u) {
    if (u == n + 1) {
        if (check()) ans = min(ans, cost);
        return;
    }
    for (int i = 2; i <= m + 1; i++) {
        c[i] += g[u][i];
    }
    cost += g[u][1];
    dsf(u + 1);
    for (int i = 2; i <= m + 1; i++) {
        c[i] -= g[u][i];
    }
    cost -= g[u][1];
    dsf(u + 1);
}

int main() {
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m + 1; j++)
            scanf("%d", &g[i][j]);
    dsf(1);
    cout << ans << endl;
    getchar();
    return 0;
}
