/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace IntroductionToAlgorithm\Chapter3\LinkedList_class.cpp
 *@data      2023/11/21 21:17:50
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

class Linkedlist {
public:
    void init(int i) {
        head->val = i;head->prev = NULL;head->next = NULL;Node = head;
    }
    void add(int x) {
        Llist *qwq = new Llist;
        qwq->val = x;qwq->next = NULL; //初始化
        qwq->prev = Node;Node->next = qwq; //链接一下
        Node = Node->next;
    }
    void Print() {
        Node = head;
        while(Node->next != NULL) {
            cout << Node->val << ' ';
            Node = Node->next;
        }
        cout << Node->val << ' ';
    }
    void Delete(int k) { //删除元素值为k的点
        if(head->val == k) {
            head = head->next;
            return;
        }
        Node = head->next;
        pre = head;
        while(Node->next != NULL) {
            if(Node->val == k) {
                pre->next = Node->next;
                return;
            }
            pre = Node;
            Node = Node->next;
        }
        if(Node->val == k)pre->next = NULL;
    }
private:
    struct Llist { int val;Llist *prev, *next; };
    Llist *head = new Llist, *Node, *pre;
    Llist *Search(int k) {
        Node = head;
        while(Node->next != NULL) {
            if(Node->val == k)return Node;
            Node = Node->next;
        }
        if(Node->val == k)return Node;
        else return NULL;
    }
};


void solve() {
    int n, m, i, j;
    Linkedlist qwq;
    qwq.init(5);
    for(i = 0;i < 10;++i)qwq.add(i);
    for(i = 1;i < 10;i += 2)qwq.Delete(i);
    qwq.Print();
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}