/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\2.29\B.cpp
 *@data      2024/02/29 18:57:56
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int x, y;
    //存坐标的哈希表
    unordered_map<int, int>qwqx;
    unordered_map<int, int>qwqy;
    for(int i = 0;i < 3;++i) {
        cin >> x >> y;
        if(!qwqx.count(x))qwqx[x] = 0; //判断字典中有无该键
        if(!qwqy.count(y))qwqy[y] = 0;
        ++qwqx[x]; //累加
        ++qwqy[y];
    }
    for(auto a : qwqx)if(a.second == 1)x = a.first; //输出只有一个的x坐标
    for(auto b : qwqy)if(b.second == 1)y = b.first;
    cout << x << " " << y;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //`cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}