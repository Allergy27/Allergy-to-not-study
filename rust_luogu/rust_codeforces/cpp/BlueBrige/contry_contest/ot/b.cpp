/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace BlueBrige\contry_contest\b.cpp
 *@date      2024/05/31 19:47:52
 */
#include<bits/stdc++.h>
#define ll long long
bool a[2415229];
long long int b[1000000];
using namespace std;

void solve() {
    int n = 2415229;
    for(int i = 2;i <= n;i++) {
        if(a[i] == 0)
            for(int j = i * 2;j <= 2415229;j += i) {
                a[j] = 1;
            }
    }
    int temp = 1;
    for(int i = 2;i <= 2415229;i++) {
        if(a[i] == 0)
            b[temp++] = i;
    }

    long long sum = 0;
    for(int i = 1;i <= temp;i++) {
        for(int j = i + 1;j <= temp;j++) {

            if(b[i] * b[i] * b[j] * b[j] >= 2333 && b[i] * b[i] * b[j] * b[j] <= 23333333333333)
                sum++;
            if(b[i] * b[i] * b[j] * b[j] >= 23333333333333)
                break;
        }

    }
    cout << sum;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}