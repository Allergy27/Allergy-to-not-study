/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\2.27\C.cpp
 *@data      2024/02/27 19:06:40
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string qwq;
    cin >> qwq;
    //非常简洁的做法
    int an = 1, ans; // an 为和首字符相等的个数
    for(int i = 1;i < qwq.size();++i)if(qwq[i] != qwq[0] || !an++)ans = an == i ? an + 1 : 1;
    //判断和首字符个数是否相等：如果相等，说明当前位就是不同的那个；如果不相等，说明第一位是不相同的那个
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}