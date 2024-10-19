/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\4.20\b.cpp
 *@date      2024/04/20 18:22:37
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, i = 0;
    cin >> n;
    while(n--) {
        if(++i % 2)cout << "CCUT";
        else cout << "TUCC";
    }
}

int main() {
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}