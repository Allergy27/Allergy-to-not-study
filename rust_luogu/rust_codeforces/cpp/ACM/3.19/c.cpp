/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.19\c.cpp
 *@date      2024/03/19 20:21:30
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    for(int a = 0;a * a <= n;++a)
        for(int b = a;b * b <= n;++b)
            for(int c = b;c * c <= n;++c)
                for(int d = c;d * d <= n;++d) {
                    if(a * a + b * b + c * c + d * d == n) {
                        cout << a << ' ' << b << ' ' << c << ' ' << d;
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