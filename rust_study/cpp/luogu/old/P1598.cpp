/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1598.cpp
 *@date      2024/04/09 17:54:56
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string str;
    vector<int>qwq(26);
    int chr = 0;
    for(int i = 0; i < 4;++i) {
        getline(cin, str);
        for(auto x : str)
            if('A' <= x && x <= 'Z')
                ++qwq[x - 'A'];
    }
    int mx = *max_element(qwq.begin(), qwq.end());

    for(int i = mx;i > 0;--i) {
        for(int j = 0;j < 26;++j)if(qwq[j] >= i)chr = j;
        for(int j = 0;j < chr;++j)cout << (qwq[j] >= i ? "* " : "  ");
        cout << "*\n";
    }
    int i = 0;
    for(i = 0; i < 25;++i)cout << (char) ('A' + i) << ' ';
    cout << "Z";
}

int main() {
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}