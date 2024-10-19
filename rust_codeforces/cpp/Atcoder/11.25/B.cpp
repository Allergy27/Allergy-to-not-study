/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\11.25\B.cpp
 *@data      2023/11/25 20:04:01
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, l, r, m, i, j;
    cin >> n >> l >> r;
    vector<int>qwq(n);
    for(auto &x : qwq) {
        cin >> x;
        if(x <= l)cout << l << ' ';
        else if(x <= r)cout << x << ' ';
        else cout << r << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}