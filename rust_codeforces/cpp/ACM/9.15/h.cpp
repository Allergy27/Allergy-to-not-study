/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\9.15\h.cpp
 *@date      2024/09/15 23:33:10
 */
#include<bits/stdc++.h>
//#define int long long

using namespace std;
using ll = long long;
int inf = 0x3f3f3f3f;

void solve() {
    int n, m, k, ans = 0;
    cin >> n >> k;
    string s;
    int qwq[26] = { 0 };
    cin >> s;
    for(int i = 0;i < n;++i)++qwq[s[i] - 'a'];
    for(int i = 0;i < 26;++i)ans += (qwq[i] & 1);
    if(ans > k + 1)cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}