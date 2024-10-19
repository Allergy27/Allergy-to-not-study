/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Ee.cpp
 *@date      2024/09/14 21:30:53
 */
#include <bits/stdc++.h>
// #define int long long

using namespace std;

struct v {
  int l, r;
};

void solve() {
  auto c_sum = [](int n) { return ((n + 1) * n) >> 1; };
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  sort(a.begin(), a.end());
  vector<v> qwq;
  qwq.emplace_back(v{0, 0});
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1])
      ++qwq[i - 1].r;
    else
      qwq.emplace_back(v{qwq[i - 1].r + 1, qwq[i - 1].r + 1});
  }
  int len = qwq.size(), ans = 0;
  for (int i = 0; i < len; ++i)
    ans += c_sum(qwq[i].l) + c_sum(n - qwq[i].r - 1);
  cout << c_sum(n) - ans;
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
  cin >> t;
  return 0;
}