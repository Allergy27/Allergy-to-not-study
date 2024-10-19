/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.20\E.cpp
 *@date      2024/03/29 06:43:16
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, i, j, k;
    cin >> n;
    vector<char>qwq(n);
    for(auto &x : qwq)cin >> x;
    for(i = 1; i <= n; ++i) {
        if(!(n % i)) {
            int f = 2;
            for(j = 0;j < i;++j)
                for(k = j + i;k < n;k += i)
                    if(qwq[k] != qwq[j])--f;
            if(f > 0) {
                cout << i << '\n';
                return;
            }
            f = 2;
            for(j = n - i;j < n;++j)
                for(k = j - i;k >= 0;k -= i)
                    if(qwq[k] != qwq[j])--f;
            if(f > 0) {
                cout << i << '\n';
                return;
            }

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