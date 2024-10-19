/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.23\C.cpp
 *@data      2023/12/24 14:21:42
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, i, ans = 0;
    cin >> n >> n;
    vector<int> qwq(n);
    for(auto &x : qwq)cin >> x;
    for(i = n % 2 == 0 ? 1 : 2;i < n;i += 2)ans += qwq[i] - qwq[i - 1];
    if(n % 2 == 1) {
        int now = ans;
        for(i = 1;i < n;i += 2) {
            now += 2 * qwq[i] - qwq[i - 1] - qwq[i + 1];
            ans = min(ans, now);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}