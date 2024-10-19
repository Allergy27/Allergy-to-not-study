/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.20\b.cpp
 *@date      2024/03/20 19:20:58
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int mi = 0, mx = INT_MAX;
    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        int r = a / b, l = a / (b + 1) + 1;
        mi = max(mi, l), mx = min(mx, r);
    }
    cout << mi << ' ' << mx << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}