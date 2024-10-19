/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\P1603.cpp
 *@data      2024/02/26 18:04:29
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, i;
    vector<int> ans;
    string m;
    vector<string> qvq = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty" };
    unordered_map<string, int> qwq;
    for(i = 1;i <= 20;++i)qwq.insert(pair<string, int>(qvq[i - 1], (i * i) % 100));
    qwq["a"] = 1;
    qwq["both"] = 4;
    qwq["another"] = 1;
    qwq["first"] = 1;
    qwq["second"] = 4;
    qwq["third"] = 9;
    while(cin >> m && m != ".")if(qwq.count(m))ans.emplace_back(qwq[m]);
    sort(ans.begin(), ans.end());
    if(ans.empty())cout << 0;
    else {
        bool flag = false;
        for(auto x : ans) {
            if(flag && x < 10)cout << 0;
            flag = true;
            cout << x;
        }
    };
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}