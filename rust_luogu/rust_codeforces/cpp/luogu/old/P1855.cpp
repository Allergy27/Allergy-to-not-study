/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1855.cpp
 *@date      2024/04/09 19:36:36
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, i, j, k, M, T, a, b;
    cin >> n >> M >> T;
    vector<vector<int>>qwq(M + 1, vector<int>(T + 1));
    for(i = 0;i < n;++i) {
        cin >> a >> b;
        for(j = M;j >= a;--j)
            for(k = T;k >= b;--k)
                qwq[j][k] = max(qwq[j][k], qwq[j - a][k - b] + 1);
    }
    cout << qwq[M][T];
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}