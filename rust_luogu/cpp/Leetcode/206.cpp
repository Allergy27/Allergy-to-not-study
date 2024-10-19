/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Leetcode\206.cpp
 *@data      2023/11/28 20:59:51
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct llist{
    int val;
    llist *next;
};



void solve() {
    int n=5, m, i, j;
    llist *qwq = new llist;
    llist *head = qwq;
    while(n--) {
        qwq->val = 5-n;
        llist *qaq = new llist;
        qwq->next = qaq;
        qwq = qwq->next;
    }
    qwq = NULL;
    llist *now = head, *res = NULL;
        while(now!=NULL){
            llist *pre = new llist;
            pre->val = now->val;
            pre->next = res;
            res=pre;
            now=now->next;
        }
    cout << head->val;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}