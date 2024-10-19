/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace BlueBrige\prectice\3.cpp
 *@date      2024/04/13 07:55:17
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, p,ans=1;
    cin >> n >> m >> p;
    while(m) {
        if(m & 1)ans = (ans * n) % p;
        b >>= 1;
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