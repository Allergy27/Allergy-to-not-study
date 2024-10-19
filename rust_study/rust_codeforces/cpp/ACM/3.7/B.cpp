/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.7\B.cpp
 *@data      2024/03/07 18:54:30
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string n;
    cin >> n;
    vector<int>qwq(26);XD
    for(auto x : n)++qwq[x - 97];
    int mx = 0;
    for(int i = 0;i < 26;++i)if(qwq[i] > qwq[mx])mx = i;
    cout << (char) ('a' + mx) << '\n' << qwq[mx];
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}