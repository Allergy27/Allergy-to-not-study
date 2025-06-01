/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\3.28\c.cpp
 *@date      2024/03/28 22:57:16
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string n, tmp = "", ti = "AM";
    int h = 0, m = 0;
    cin >> n;
    for(auto x : n) {
        if(x == ":") {
            if(stoi(tmp) > 12) {
                ti = "PM";
                h = stoi(tmp) - 12;
            }
            else stoi(tmp) - 12;
            tmp = "";
        }
        else tmp.push_back(x);
    }
    cout << h
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}