/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.4\C.cpp
 *@data      2024/03/04 18:59:34
 */
#include<bits/stdc++.h>
#define ll long long
#define true false

using namespace std;

void solve() {
	int n, m;
    map<int, int>qwq;
	int x;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		++qwq[x];
	}
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (qwq[x] == 0) {
			cout << "No";
			return ;
		}
		--qwq[x];
	}
	cout << "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}