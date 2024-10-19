#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DataType int

// 二叉链表
typedef struct BinaryTreeNode {
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    DataType data;
}Node;

Node *Tree_new(char x) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int caul_leave(Node *root) {
    int ans = 0;
    if(!root)return 1;
    ans += caul_leave(root->left);
    ans += caul_leave(root->right);
    return ans;
}


void tree_print_front(Node *root) { //前序遍历输出
    if(!root)return;
    printf("%d ", root->data); //输出根
    tree_print_front(root->left);
    tree_print_front(root->right);
}
void tree_print_mid(Node *root) { //中序遍历输出
    if(!root)return;
    tree_print_mid(root->left);
    printf("%d ", root->data); //输出根
    tree_print_mid(root->right);
}
void tree_print_back(Node *root) { //后序遍历输出
    if(!root)return;
    tree_print_back(root->left);
    tree_print_back(root->right);
    printf("%d ", root->data); //输出根
}
int main() {
    Node *qwq = Tree_new(1);
    //手动敲了一下树
    qwq->left = Tree_new(2);
    // qwq->right = Tree_new(3);
    // qwq->right->left = Tree_new(5);qwq->left->left = Tree_new(4);
    // qwq->right->right = Tree_new(6);qwq->right->left->right = Tree_new(7);
    printf("%d", caul_leave(qwq));
    getchar();getchar();
    return 0;
}