/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace BlueBrige\contry_contest\c.cpp
 *@date      2024/05/31 22:17:49
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;
int a[100001];
int b[100001];
int sum;
void solve() {
    int n;
    cin >> n;
    sum = n;
    for(int i = 1;i <= n;i++)
        cin >> a[i], b[a[i]]++;
    for(int i = 1;i <= 100000;i++) {
        if(b[i] >= 2)
            sum -= 2;
    }
    cout << sum / 2;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    solve();
    cin >> t;
    return 0;
}