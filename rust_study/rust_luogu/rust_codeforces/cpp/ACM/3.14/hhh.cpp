/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.14\hhh.cpp
 *@date      2024/03/14 19:32:35
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;
map<long long, long long> qwq; //全局变量存 n 的质因子
void pri_split(long long n) {
    long long ans = 1;

    for(ll i = 2;i * i <= n;i++)
        while(!(n % i))qwq[i]++, n /= i;
    qwq[n] = 1;
}

void solve() {
    ll x;
    cin >> x;
    pri_split(x);
    for(auto y : qwq)cout << y.first << ' ' << y.second << '\n';
}

int main() {
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}

