/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.3\B.cpp
 *@data      2024/03/03 18:41:40
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string qwq; //用来读字符串
    int qvq[] = { 1, 3, 6 }; //对应: 都相同 两个相同 都不相同
    cin >> qwq;
    set<char> qaq;
    for(auto x : qwq)qaq.insert(x); //直接用set记录不同的个数，减少码量
    cout << qvq[qaq.size() - 1];
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}