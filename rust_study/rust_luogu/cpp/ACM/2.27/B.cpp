/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\2.27\B.cpp
 *@data      2024/02/27 18:56:10
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    bool f = true;
    int n;
    char x = 'K';
    cin >> n;
    vector<char>qwq(n);
    for(auto &u : qwq)cin >> u;
    for(int i = 0; i < n;++i) {
        if((qwq[i] == x) && f)f = false;
        x = qwq[i];
    }
    cout << (f ? "Yes" : "No");
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}