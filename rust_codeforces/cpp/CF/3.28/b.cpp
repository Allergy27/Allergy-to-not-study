/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\3.28\b.cpp
 *@date      2024/03/28 22:51:44
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j;
    cin >> n;
    for(i = 0;i < n;++i) {
        if(i % 2 == 0) {
            for(j = 0;j < n;++j)cout << (j % 2 == 0 ? "##" : "..");
            cout << '\n';
            for(j = 0;j < n;++j)cout << (j % 2 == 0 ? "##" : "..");
            cout << '\n';
        }
        if(i % 2 == 1) {
            for(j = 0;j < n;++j)cout << (j % 2 != 0 ? "##" : "..");
            cout << '\n';
            for(j = 0;j < n;++j)cout << (j % 2 != 0 ? "##" : "..");
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}