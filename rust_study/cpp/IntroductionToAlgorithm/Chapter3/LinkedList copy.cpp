/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace IntroductionToAlgorithm\Chapter3\LinkedList.cpp
 *@data      2023/11/21 19:50:57
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct LinkedList {
    int val;
    LinkedList *prev;
    LinkedList *next;
};

void solve() {
    int n, m, i, j;
    cin >> n;
    LinkedList *qwq; //中间变量
    cin >> m;
    qwq->val = m;qwq->prev = NULL; //初始化值
    LinkedList *head = qwq; //设置头指针
    while(--n) {
        LinkedList *qvq = new LinkedList; //为链表分配空间
        cin >> m;
        qvq->val = m;qvq->next = NULL; //初始化
        qvq->prev = qwq;qwq->next = qvq; //链接一下
        qwq = qwq->next;
    }
    int sum = 0, count = 0;
    while(head->next != NULL) {
        if((++count) % 2 == 0)sum += head->val;
        head = head->next;
    }
    cout << sum + ((count + 1) % 2 == 0) ? head->val : 0;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}