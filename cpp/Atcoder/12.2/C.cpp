/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\12.2\C.cpp
 *@data      2023/12/02 20:21:51
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, i;
    cin >> n;
    vector<ll>qwq(n);
    for(auto &x : qwq)cin >> x;
    vector<ll>qvq(qwq); //因为最后按原数组序输出，所以复制一个
    unordered_map<int, int>ck; //哈希表检索位置
    sort(qvq.begin(), qvq.end()); //排序确定比这个数大的和是多少
    ck[qvq[0] + 1] = 0; //让第一个的位置定为0
    for(i = 1;i < n;++i) {
        if(qvq[i] + 1 != qvq[i - 1] + 1) { //如果不相同，则创建一个新的键(key)
            ck[qvq[i] + 1] = ck[qvq[i - 1] + 1];
        }
        ++ck[qvq[i] + 1]; //相同则把位置向后移
    }
    vector<ll>qaq(n); //创建一个前缀和数组
    qaq[0] = qvq[0];
    for(i = 1;i < n;++i)qaq[i] = qvq[i] + qaq[i - 1]; //初始化前缀和数组
    for(auto x : qwq)cout << qaq[n - 1] - qaq[ck[x + 1]] << ' '; //按位置输出即可
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}