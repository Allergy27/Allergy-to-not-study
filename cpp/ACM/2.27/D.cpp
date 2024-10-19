/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\2.27\D.cpp
 *@data      2024/02/27 19:40:41
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string n;
    cin >> n;
    for(auto &x : n)x &= -33;
    cout << n;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}