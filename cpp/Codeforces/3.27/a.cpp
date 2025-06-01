/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\3.27\a.cpp
 *@date      2024/03/27 18:54:41
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    int p = (n - 1) / 2;
    vector<int>qwq(n);
    for(auto &x : qwq)cin >> x;
    sort(qwq.begin(), qwq.end());
    while(p + 1 < n && qwq[p] == qwq[p + 1]) {
        ans++;
        p++;
    }
    cout << ans + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}