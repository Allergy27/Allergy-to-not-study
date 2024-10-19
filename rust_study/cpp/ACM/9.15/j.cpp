/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\9.15\j.cpp
 *@date      2024/09/16 00:21:06
 */
#include<bits/stdc++.h>
//#define int long long

using namespace std;
using ll = long long;
int inf = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>qwq(k);
    vector<int>dp(n + 1);
    for(auto &x : qwq)cin >> x;
    for(int i = 0;i <= n;++i)
        for(int j = 0;j < k;++j)
            if(i >= qwq[j])dp[i] = max(dp[i], i - dp[i - qwq[j]]);
    cout << dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}