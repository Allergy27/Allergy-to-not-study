/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\test.cpp
 *@data      2023/11/20 17:36:59
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j;
    cin >> n;
    set<int> qvq{ 1, 2 };
    set<set<int>> qwq;
    set<set<int>> qaq;
    qwq.emplace(qvq);
    qaq.emplace(qvq);
    if(qwq == qaq)cout << 'y';
    else cout << 'n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while(t--)solve();
    cin >> t;
    return 0;
}