/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.16\D.cpp
 *@data      2023/12/17 18:33:39
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int dfs(vector<vector<int>> &tree, int node, int fa) {
    int ans = 1;
    for(auto &x : tree[node]) {
        if(x != fa) {
            int k = dfs(tree, x, node);
            if(node != 1)ans += k;
            else ans = max(ans, k + 1);
        }
    }
    return ans;
}


void solve() {
    int n, m, i, j, a, b;
    cin >> n;
    vector<vector<int>>qwq(n + 1);
    for(i = 1;i < n;++i) {
        cin >> a >> b;
        qwq[a].emplace_back(b);
        qwq[b].emplace_back(a);
    }
    m = dfs(qwq, 1, 1);
    cout << n  - m+1;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}