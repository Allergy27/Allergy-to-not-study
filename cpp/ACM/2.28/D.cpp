/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\2.28\D.cpp
 *@data      2024/02/28 18:49:22
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, ans = 0;
    cin >> n;
    vector<int>qwq(n);
    for(auto &x : qwq) {
        cin >> x;
        ans += x;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}