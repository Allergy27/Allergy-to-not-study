/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.5\3.cpp
 *@data      2024/03/05 19:34:15
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j;
    cin >> n >> m;
    vector<vector<int>>qwq(n, vector<int>(m));
    for(i = 0;i < n;++i)for(auto &x : qwq[i])cin >> x;
    for(i = 0;i < m;++i) {
        for(j = n - 1;j >= 0;--j)cout << qwq[j][i] << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}