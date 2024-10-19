/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace IntroductionToAlgorithm\Chapter3\Tree.cpp
 *@data      2023/11/23 17:36:12
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;


class Tree { //二叉查找树
public:
    void init(int x) { //初始化
        this->val = x;
        this->p = NULL;
        this->left = NULL;
        this->right = NULL;
    }
    void add(int x) { //添加新元素
        Tree *root = this;
        Tree *son = new Tree;
        son->init(x);
        while(true) {
            if(x < root->val) { //新元素满足小于根节点
                if(root->left == NULL) { //左子树为空
                    son->p = root;
                    root->left = son;
                    break;
                }
                else root = root->left; //非空向左搜索
            }
            else { //大于等于根节点
                if(root->right == NULL) { //右子树为空
                    son->p = root;
                    root->right = son;
                    break;
                }
                else root = root->right; //非空向右搜
            }
        }
    }

    void INORDER_TREE() { //中序遍历
        Tree *x = this;
        INORDER_TREE_WALK(x);
    }

    void Tree_Search(int k) { //搜索
        Tree *x = this;
        Tree *tmp = Search(x, k);
        if(tmp != NULL)cout << "\n" << tmp->val;
        else cout << "\n-1";
    }
private:
    int val;
    Tree *p, *left, *right;
    void INORDER_TREE_WALK(Tree *x) { //中序遍历底层
        if(x != NULL) {
            INORDER_TREE_WALK(x->left);
            cout << x->val << ' ';
            INORDER_TREE_WALK(x->right);
        }
    }
    Tree *Search(Tree *x, int k) { //搜索底层
        if(x == NULL || k == x->val)return x;
        if(k < x->val)return Search(x->left, k);
        else return Search(x->right, k);
    }
};

void solve() {
    Tree *qwq = new Tree;
    qwq->init(527);

    vector<int>pvp(27);
    for(auto &x : pvp)x = rand() % 1000;

    for(auto x : pvp)qwq->add(x); //创建二叉查找树

    qwq->INORDER_TREE(); //中序遍历这棵树
    qwq->Tree_Search(527); //查找527
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