/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\3.12\c.cpp
 *@date      2024/03/12 19:26:56
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    stack<int> qwq; //存左括号
    for(int i = 0; i < n; i++) {
        if(s[i] == '-') cout << i + 1 << ' ';
        else if(s[i] == '(') qwq.push(i + 1);  // 左括号入栈
        else {  // 找到一组匹配
            cout << i + 1 << ' ' << qwq.top() << ' ';
            qwq.pop();  // 左括号出栈
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}
