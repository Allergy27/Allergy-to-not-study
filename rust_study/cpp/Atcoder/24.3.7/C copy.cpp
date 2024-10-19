/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\24.3.7\C.cpp
 *@date      2024/03/17 18:51:17
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string n;
    vector<int>qwq(26);
    cin >> n;
    ll l = n.size();
    ll ans = l * l;
    for(auto x : n)
        ++qwq[x - 'a'];
    for(int i = 0;i < 26;++i) {
        if(qwq[i] == l) {
            ans = 2;break;
        }
        ans -= qwq[i] * qwq[i];
    }
    cout << ans / 2;

}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}