/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace BlueBrige\4.10\5.cpp
 *@date      2024/04/12 13:54:59
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int>dp(10);
    for(int i = 1;i <= n;++i) {
        string s;cin >> s;
        int a = s.front() ^ 48, b = s.back() ^ 48;
        dp[b] = max(dp[b], dp[a] + 1);
    }
    cout << n - *max_element(dp.begin(),dp.end());
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}