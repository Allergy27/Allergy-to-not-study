/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace DP\Direct_DP\7_P2679.cpp
 *@date      2024/04/06 19:07:40
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, m, i, j, k, kn;
    cin >> n >> m >> kn;
    string a, b;
    cin >> a >> b;
    vector<vector<ll>>qwq(m + 1, vector<ll>(kn + 1));
    qwq[0][0] = 1;
    vector<vector<ll>>qvq(m + 1, vector<ll>(kn + 1));
    for(i = 1; i <= n;++i)
        for(j = m;j > 0;--j)
            for(k = kn;k > 0;--k) {
                qvq[j][k] = a[i - 1] == b[j - 1] ? qvq[j - 1][k] + qwq[j - 1][k - 1] : 0;
                qwq[j][k] = (qwq[j][k] + qvq[j][k]) % 1000000007;
            }
    cout << qwq[m][kn];
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}