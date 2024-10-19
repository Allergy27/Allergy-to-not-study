/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.16\E.cpp
 *@data      2023/12/16 21:12:08
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j,p,q;
    cin >> n;
    vector<pair<int, int>> op;
    vector<int> op1;
    vector<int> op2;
    vector<int> all_op;
    for(i = 0;i < n;++i) {
        cin >> p >> q;
        op.emplace_back(make_pair(p, q) );
    }
    for(i = n - 1;i >= 0;--i) {
        if(op[i].first - 1)op2.emplace_back(op[i].second);
    }
    cout << op[0].first;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}