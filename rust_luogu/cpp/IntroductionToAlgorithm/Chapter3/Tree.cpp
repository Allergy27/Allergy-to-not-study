/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace IntroductionToAlgorithm\Chapter3\Tree.cpp
 *@data      2023/11/23 17:36:12
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;


struct Tree {
    int val;
    Tree *p;
    Tree *left;
    Tree *right;
};

void init(Tree *tree, int x) { //初始化
    tree->val = x;
    tree->p = NULL;
    tree->left = NULL;
    tree->right = NULL;
}

void INORDER_TREE_WALK(Tree *x) { //中序遍历
    if(x != NULL) {
        INORDER_TREE_WALK(x->left);
        cout << x->val << ' ';
        INORDER_TREE_WALK(x->right);
    }
}


Tree *Tree_Search(Tree *x, int k) { //搜索
    if(x == NULL || k == x->val)return x;
    if(k < x->val)return Tree_Search(x->left, k);
    else return Tree_Search(x->right, k);
}

void solve() {
    int n, m, i, j;
    Tree *qwq = new Tree;
    init(qwq, 527);
    Tree *head = qwq;
    vector<int>pvp(27);
    for(auto &x : pvp)x = rand() % 1000;
    for(auto x:pvp) { //创建二叉查找树
        bool flag = true;
        Tree *tmp = new Tree;
        tmp->val = x;
        tmp->left = NULL;
        tmp->right = NULL;
        while(flag) {
            if(tmp->val < qwq->val) {
                if(qwq->left == NULL) {
                    tmp->p = qwq;
                    qwq->left = tmp;
                    flag = false;
                }
                else qwq = qwq->left;
            }
            else
                if(qwq->right == NULL) {
                    tmp->p = qwq;
                    qwq->right = tmp;
                    flag = false;
                }
                else qwq = qwq->right;
        }
        qwq = head;
        tmp = NULL;
    }
    INORDER_TREE_WALK(qwq); //中序遍历这棵树
    qwq = head;
    int res;
    Tree *qaq = Tree_Search(qwq, 527);
    if(qaq != NULL)cout << '\n' << qaq->val;
    else cout << "\n0";

}

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}