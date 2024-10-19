/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace BlueBrige\contry_contest\a.cpp
 *@date      2024/05/31 19:29:40
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;
int a[5] = { 0, 2, 0, 2, 3 };
int qian, bai, shi, ge;
void solve() {
    int temp = 1;int n;
    int sum = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {

        qian = i / 1000;bai = i / 100 % 10;shi = i / 10 % 10;ge = i % 10;
        if(i < 1000)qian = -1;
        if(i < 100)bai = -1;
        if(i < 10)shi = -1;
        if(qian == a[temp])
            temp++;
        if(temp == 5) {
            temp = 1;
            sum++;
        }
        if(bai == a[temp])
            temp++;
        if(temp == 5) {
            temp = 1;
            sum++;
        }
        if(shi == a[temp])
            temp++;
        if(temp == 5) {
            temp = 1;
            sum++;
        }
        if(ge == a[temp])
            temp++;
        if(temp == 5) {
            temp = 1;
            sum++;
        }
    }
    cout << sum;

}

int main() {
    // ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}