/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.10\B.cpp
 *@data      2023/12/10 20:03:10
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j, k, g, gnow = 0,mnow=0;
    cin >> k >> g >> m;
    while(k--){
        if(gnow == g)gnow = 0;
        else if(mnow == 0)mnow = m;
        else {
            gnow += mnow;
            mnow = 0;
            if(gnow > g) {
                mnow = gnow - g;
                gnow = g;
            }
        }
    }
    cout << gnow << ' ' << mnow;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}