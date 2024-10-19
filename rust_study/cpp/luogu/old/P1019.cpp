/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1019.cpp
 *@data      2023/11/25 14:10:52
 */
#include<bits/stdc++.h>

#include<numeric>
#define ll long long

using namespace std;

int used[22], ans = 0, n, k;
string str;

void dfs(string word[], int nums, string now) {
    if(now.length() > ans)ans = now.length();
    for(int i = 0;i < n;++i) {
        if(used[i] < 2) {
            for(int j = 1;j <= word[i].length();++j) {
                k = now.find(word[i].substr(0, j), now.length() - j);
                if(k != string::npos) {
                    ++used[i];
                    str = now;
                    str.replace(k, word[i].length(), word[i]);
                    dfs(word, nums + 1, str);
                    --used[i];
                    break;
                }
            }
        }
    }
}


void solve() {
    int i, j;
    char head;
    cin >> n;
    string qwq[22];
    for(i = 0;i < n;++i)cin >> qwq[i];
    cin >> head;
    for(i = 0;i < n;++i) {
        if(qwq[i][0] == head) {
            ++used[i];
            dfs(qwq,1,qwq[i]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}