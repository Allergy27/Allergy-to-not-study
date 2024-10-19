/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.11\B.cpp
 *@date      2024/03/11 18:35:50
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n;
    cin >> n;
    while(n % 2 == 0 || n % 3 == 0) {
        if(n % 2 == 0)n /= 2;
        if(n % 3 == 0)n /= 3;
    }
    cout << (n == 1 ? "Yes" : "No");
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}