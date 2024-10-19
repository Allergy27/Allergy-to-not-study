/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.20\g.cpp
 *@date      2024/03/29 00:14:52
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j;
    map<string, int>qwq1;
    map<string, int>qwq2;
    cin >> n;
    vector<int>dp(n + 1);
    for(i = 0;i < n;++i) {
        string a, b;
        cin >> a >> b;
        dp[i + 1] = max(dp[i], max(dp[qwq1[a]] + 1, dp[qwq2[b]] + 1));
        qwq1[a] = i;
        qwq2[b] = i;
    }
    cout << n - dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}