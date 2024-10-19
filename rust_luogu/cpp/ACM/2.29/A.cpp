/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\2.29\A.cpp
 *@data      2024/02/29 18:45:11
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, i;
    string qvq;
    vector<int> qwq(10);
    cin >> qvq;
    for(auto x : qvq)qwq[x ^ 48] = 1; //异或48，将字符型数字转为普通数字 （-48也行)
    for(i = 0;i < 10;++i)if(qwq[i] == 0)cout << i; //判断少了哪个输出
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}