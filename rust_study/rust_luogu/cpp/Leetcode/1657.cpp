/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Leetcode\1657.cpp
 *@data      2023/11/30 10:40:31
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string word1, word2;
    cin >> word1;
    cin >> word2;
    if(word1.size() != word2.size())return;
    int qwq[26]={0},qaq[26]={0};
    for(auto x:word1)++qwq[x-'a'];
    for(auto x:word2)++qaq[x-'a'];
    vector<int>count1,count2;
    for(int i=0;i<26;++i)if(!qwq[i]^!qaq[i])return;
    sort(count1.begin(),count1.end());
    sort(count2.begin(),count2.end());
    if(count1!=count2)return;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}