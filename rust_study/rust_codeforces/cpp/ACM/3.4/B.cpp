/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.4\B.cpp
 *@data      2024/03/04 18:55:48
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string n;
    cin >> n;
    vector<char> qwq;
    for(auto x : n)qwq.emplace_back(x);
    sort(qwq.begin(), qwq.end());
    for(auto x : qwq)cout << x;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}