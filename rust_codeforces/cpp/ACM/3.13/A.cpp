/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.13\A.cpp
 *@date      2024/03/13 18:58:32
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k, l = 1, r = 0, ans;
    cin >> n >> k;
    vector<pair<int, int>>qwq(n);
    for(auto &x : qwq) {
        cin >> x.first >> x.second;
        int mx = max(x.first, x.second);
        r = max(mx, r); //确定一个二分最大值，这里其实也可以给一个很大的值减少代码量
    }
    while(l <= r) { //二分答案
        int mid = l + r >> 1;
        //check() 按一般背的板子来是写一个 check() 我这里为了方便直接写这里面了
        int tot = 0;
        for(auto x : qwq)tot += (x.first / mid) * (x.second / mid);
        if(tot < k)r = mid - 1;
        //check()截止
        else l = mid + 1;
    }
    cout << r;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}