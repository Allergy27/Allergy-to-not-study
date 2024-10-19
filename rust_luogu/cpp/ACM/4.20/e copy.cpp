/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\4.20\e.cpp
 *@date      2024/04/20 19:38:46
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int>qaq(n);
    for(auto &x:qaq)cin >> x;
    sort(qaq.begin(), qaq.end());
    int  ans = qaq[n - 1] - qaq[0];
    for(int i = 1;i < n - 1;++i) {
        int x = max(abs(qaq[i + 1] - qaq[i - 1]), abs(qaq[i] - qaq[n - 1]));
        ans = min(x, ans);
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