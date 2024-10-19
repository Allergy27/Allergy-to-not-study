/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.2\B.cpp
 *@data      2023/12/03 16:36:35
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j, s, l;
    cin >> n >> s >> m >> l;
    int sum = n * (s + m + l);
    for(int S = 0;S < n / 6 + 2;++S)
        for(int M = 0;M < n / 8 + 2;++M)
            for(int L = 0;L < n / 12 + 2;++L)
                if(S * 6 + M * 8 + L * 12 >= n && S * s + M * m + L * l < sum)sum = S * s + M * m + L * l;
    cout << sum;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}