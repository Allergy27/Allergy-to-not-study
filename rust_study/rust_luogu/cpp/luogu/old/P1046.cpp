/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1046.cpp
 *@data      2023/11/24 21:27:37
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m=0, i, j;
    vector<int>qwq(10);
    for(auto &x : qwq)cin >> x;
    cin >> n;
    for(auto x : qwq)
        if(x <= n + 30)++m;
    cout << m;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}