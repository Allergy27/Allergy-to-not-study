#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Depth[100];

typedef int BTDataType;
typedef struct BinaryTreeNode {
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    BTDataType data;
}BTNode;

BTNode *new(char data){
    BTNode * node = (BTNode *) malloc(sizeof(BTNode));
node->data = data;
node->left = NULL;
node->right = NULL;
return node;
}

BTDataType find(BTNode *root, BTDataType goal, BTDataType fa) {
    if(!root)return 0;
    if(root->data == goal)return fa;
    BTDataType l = find(root->left, goal, root->data);
    BTDataType r = find(root->right, goal, root->data);
    return l + r;
}
void tot(BTNode *root, int depth) {
    if(!root)return;
    ++Depth[depth];
    tot(root->left, depth + 1);
    tot(root->right, depth + 1);
}
/*
void Tot(BTNode *root, int depth, int *qwq, int f) {
    if(!root)return;
    ++qwq[depth];
    Tot(root->left, depth - 1, qwq, 0);
    Tot(root->right, depth - 1, qwq, 0);
    if(f)for(int i = depth; i > 0;--i)printf("%d ", qwq[i]); //输出各层个数
}
*/
/*
typedef struct midium {
    BTNode *val;
    int dep;
}Mid;

Mid cM(BTNode *a, int b) {
    Mid x = { a, b };
    return x;
}

Mid stack[100];
void Tot(BTNode *root, int depth) {
    if(!root)return;
    int top = 0, ans = 0;
    stack[top] = cM(root, 1);
    while(top + 1) {
        if(!stack[top--].val)continue;
        Mid node = stack[++top];
        if(node.dep == depth)++ans;
        stack[top++] = cM(node.val->right, node.dep + 1);
        stack[top] = cM(node.val->left, node.dep + 1);
    }
    printf("%d", ans);
}
*/

int dep[100];
BTNode *stack[100];
void Tot(BTNode *root, int depth) {
    if(!root)return;
    int top = 0, ans = 0;
    stack[top] = root, dep[top] = 1;
    while(top + 1) {
        if(!stack[top--])continue;
        BTNode *node = stack[++top];
        if(dep[top] == depth)++ans;
        int Depth = dep[top];
        dep[top] = Depth + 1, stack[top++] = node->right;
        dep[top] = Depth + 1, stack[top] = node->left;
    }
    printf("%d", ans);
}

int cbt(BTNode *root) {
    BTNode *Q[100], *p = NULL;
    int front = -1, rear = -1, flag = -1;
    if(!root)return 1;
    Q[++rear] = root;
    while(front != rear) {
        p = Q[++front];
        if(!p->left) {
            flag = 0;
            if(p->right)return 0;
        }
        else {
            if(!flag)return 0;
            Q[++rear] = p->left;
            if(!p->right)flag = 0;
            else Q[++rear] = p->right;
        }
    }
    return 1;
}


int main() {
    BTNode *qwq = new(1);
    //手动敲了一下树，这部分比较丑
    qwq->left = new(2);qwq->left->left = new(4);
    qwq->right = new(3);qwq->right->left = new(5);
    qwq->right->right = new(6);qwq->right->left->right = new(7);
    //下面是算法部分：
    printf("%d", cbt(qwq)); //输出x的双亲
    printf("\n");
    /*
    tot(qwq, 0);
    for(int i = 0;i < 4;++i)printf("%d ", Depth[i]); //输出各层个数
    */
    int all[100] = { 0 };
    // Tot(qwq, 3);
    getchar();getchar();
    return 0;
}