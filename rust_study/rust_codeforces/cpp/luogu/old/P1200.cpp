/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1200.cpp
 *@data      2024/02/26 18:55:09
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string usa, team;
    unsigned long long u = 1, t = 1;
    cin >> usa;
    cin >> team;
    for(auto x : usa)u *= x - 64;
    for(auto y : team)t *= y - 64;
    cout << (u % 47 == t % 47 ? "GO" : "STAY");
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}