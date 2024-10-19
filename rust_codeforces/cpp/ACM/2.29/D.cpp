/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\2.29\D.cpp
 *@data      2024/02/29 18:50:27
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, i, j;
    cin >> n;
    vector<int>qwq(2001); //一共只有2001个数0-2000
    for(i = 0;i < n;++i) {
        cin >> j;
        qwq[j] = 1; //标记，被标记的数不可用
    }
    for(i = 0;i < 2001;++i)if(!qwq[i]) { cout << i;break; } //从小到大遍历，输出第一个没被标记的数
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}