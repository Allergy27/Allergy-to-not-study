/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.23\A.cpp
 *@data      2023/12/24 12:35:50
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int b, g;
    cin >> b >> g;
    cout << (b > g ? "Bat" : "Glove");
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}