/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\3.27\c.cpp
 *@date      2024/03/27 20:09:25
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> qwq(n);
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        qwq[v].emplace_back(u);
        qwq[u].emplace_back(v);
    }

    auto check = [&](int x) -> bool {
        int ans = 0;
        auto dfs = [&](auto self, int v, int fa) -> int {
            int size = 1;
            for(auto u : qwq[v]) {
                if(u != fa) //排除父亲节点
                    size += self(self, u, v); //自底向上计算大小
            }
            if(size >= x && fa != v) //如果大小足够则断开连接
                ++ans, size = 0;
            return size;
            };
        int t = dfs(dfs, 0, 0);
        return (ans > k || (t >= x && ans == k));
        };

    int l = 1, r = n / (k + 1) + 1;
    while(r - l > 1) {
        int m = (l + r) / 2;
        if(check(m)) {
            l = m;
        }
        else {
            r = m;
        }
    }
    cout << l << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}