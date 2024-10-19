/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\24.3.7\C.cpp
 *@date      2024/03/17 18:51:17
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, ans = 0;
    vector<ll>qwq(26);
    bool same = false;
    string s;

    cin >> s;
    n = s.size();
    for(int i = 0;i < n;i++) {
        qwq[s[i] - 'a']++;
    }
    ans = n * n;
    for(int i = 0;i < 26;i++) {
        ans -= qwq[i] * qwq[i];
        if(qwq[i] > 1)same = true;
    }
    ans /= 2;
    if(same)ans++;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}