/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1781.cpp
 *@data      2024/01/17 20:48:13
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, ans;
    cin >> n;
    string qwq = "", x;
    for(int i = 1;i <= n;++i) {
        cin >> x;
        if(x.size() > qwq.size() || (x.size() == qwq.size()) && x > qwq) {
            qwq = x;
            ans = i;
        }
    }
    cout << ans << '\n' << qwq;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}