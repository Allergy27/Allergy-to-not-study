/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\5.18\re_c.cpp
 *@date      2024/05/18 21:00:16
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll a[1000001];

void solve() {
    int n, m, d = 0, s = 0;
    cin >> n >> m;
    int ans = n;
    for(int i = 0;i < n;++i) {
        cin >> a[i];
        if(a[i] & 1)d += (a[i] - 1); //从奇数分出来的偶数部分
        else d += (a[i] - 2), s++; //从偶数中分出来的部分
    }
    if(d / 2 >= m)cout << ans + m * 2 - 1 << '\n'; //之所以减一是因为加不加是不影响的
    else if((d / 2 + s) >= m)cout << ans + d + m - d / 2 << '\n';
    else cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}