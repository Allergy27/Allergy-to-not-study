/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\9.4\a.cpp
 *@date      2024/09/04 12:56:49
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, t;
ll ans = 0;
int ls, lt;
void dfs(int i, int x, int m) {
    if(i > ls) return;
    if(x == lt) {
        if(s[i] == t[1]) {
            dfs(i + 1, 1, 0);
            ans += x * x;
        }
        else {
            dfs(i + 1, 1, 1);
            ans += x * x;
        }
    }
    else {
        if(s[i] == t[x + 1]) {
            dfs(i + 1, t + 1, m);
        }
        else {
            if(m == 0) {
                dfs(i + 1, t + 1, m);
            }
            else {
                dfs(i + 1, 1, 1);
            }
        }
    }
}
int main() {
    cin >> (s+1);
    cin >> (t+1);
    ls = strlen(s+1);
    lt = strlen(t+1);
}