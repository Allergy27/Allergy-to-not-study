/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\11.20\1035.cpp
 *@data      2023/11/20 20:39:39
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, i = 0;
    double Sn = 0;
    cin >> n;
    while(++i) {
        Sn += 1.0 / i;//暴力求解
        if(Sn > n) {
            cout << i;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}