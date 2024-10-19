/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.12\B.cpp
 *@date      2024/03/12 19:20:03
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string n;
    cin >> n;
    ll ans = 0;
    for(int i = 1;i < n.size();++i)
        if(n[i] == '0' && n[i - 1] == '0') {
            ++ans;
            ++i;
        }
    cout << n.size() - ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}