/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace DP\Direct_DP\P1020.cpp
 *@date      2024/03/28 09:02:53
 */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve() {
    int n, ans = 0, i, j, top = 0;vector<int> qwq, qaq;
    cin >> n;

    qwq.emplace_back(n);
    qaq.emplace_back(n);

    auto bisect = [](vector<int>nums, int x) -> int {
        return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), x));
        };

    while(cin >> n) {
        if(n <= qwq[0])qwq.insert(qwq.begin(), n);
        else qwq[bisect(qwq, n) - 1] = n;

        if(n > qaq[top])qaq.emplace_back(n), ++top;
        else qaq[bisect(qaq, n)] = n;

        //下面是判断退出的
        char ch = getchar();
        if(ch == '\n')break;
    }
    cout << qwq.size() << '\n';
    cout << qaq.size();
}

int main() {
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}