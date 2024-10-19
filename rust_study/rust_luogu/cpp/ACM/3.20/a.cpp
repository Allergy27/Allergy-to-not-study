/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.20\a.cpp
 *@date      2024/03/20 18:42:27
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    bool flag = true;
    int res = 0, len = s1.size();
    for(int i = 1; i < len - 1; i++)
        if(s1[i] != s2[i])
            if(s2[i] != s2[i - 1] && s2[i] != s2[i + 1]) {
                res++;
                s2[i] ^= 1;
            }
            else flag = false;
    if(s1[len - 1] != s2[len - 1] || s1[0] != s2[0]) flag = false;
    if(flag) cout << res << '\n';
    else cout << "-1\n";
}


int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}