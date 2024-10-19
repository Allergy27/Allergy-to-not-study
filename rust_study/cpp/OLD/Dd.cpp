/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Dd.cpp
 *@date      2024/09/14 21:22:04
 */
#include<bits/stdc++.h>
//#define int long long

using namespace std;
using ll = long long;
void solve() {
    int n, q;
    cin >> n;
    vector<int> x(n);
    vector<int> p(n);
    for(int i = 0;i < n;i++)cin >> x[i];
    for(int i = 0;i < n;i++)cin >> p[i];
    vector<long long> sum(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + p[i - 1];
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        int left = lower_bound(x.begin(), x.end(), l) - x.begin();
        int right = upper_bound(x.begin(), x.end(), r) - x.begin() - 1;
        long long ans = 0;
        if(left <= right)
            ans = sum[right + 1] - sum[left];
        cout << ans << '\n';
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