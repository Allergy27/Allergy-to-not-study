/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.13\B.cpp
 *@date      2024/03/13 19:13:42
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, k, i, j,ans=0;
    cin >> n >> k;
    vector<ll>qwq(n + 1); //前缀和数组
    vector<ll>qaq(k + 1); //等效哈希表->map
    for(i = 1;i <= n;++i) {
        cin >> qwq[i];
        //qwq[i] %= k; 这个并不重要，可以省略
        qwq[i] += qwq[i - 1]; //前缀和，解题关键1
    }
    // 试了下暴力，并不能过
    for(i = 0;i <= n;++i)ans += qaq[qwq[i] % k]++; //同余，解题关键2
    cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}