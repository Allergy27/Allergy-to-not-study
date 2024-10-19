/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.10\A.cpp
 *@data      2023/12/10 19:59:33
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m,s,k, i, j,all=0,p,q;
    cin >> n >> s >> k;
    while(n--) {
        cin >> p >> q;
        all += p * q;
    }
    cout <<( all >= s ? all : all + k);
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}