/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\11.25\A.cpp
 *@data      2023/11/25 20:00:29
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, l, i=0, j;
    cin >> n >> l;
    vector<int>qwq(n);
    for(auto &x : qwq) {
        cin >> x;
        if(x >= l)++i;
    }
    cout << i;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}