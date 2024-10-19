#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DataType int

// 压栈 出栈 弹出 判空
typedef struct Stack_DataType {
    int size;
    int top;
    DataType *data;

}stack;

stack stack_new() {
    stack x;
    x.size = 27; //预存大小节省扩充开支
    x.top = -1;
    x.data = (DataType *) malloc(x.size * sizeof(DataType));
    return x;
}

void stack_push(stack *stk, DataType x) {

    if(stk->top + 1 == stk->size) {
        stk->size <<= 1;
        DataType *list = (DataType *) malloc(stk->size * sizeof(DataType));
        for(int i = 0;i < stk->size >> 1;++i)list[i] = stk->data[i];
        stk->data = list;
        free(list);
    }
    stk->data[++stk->top] = x;
}

DataType stack_get(stack *stk) {
    if(stk->top == -1) {
        puts("[WARNING] 栈为空，获取失败，返回 0");
        return 0;
    }
    return stk->data[stk->top];
}

DataType stack_pop(stack *stk) {
    if(stk->top == -1) {
        puts("[WARNING] 栈为空，删除失败，返回 0");
        return 0;
    }
    return stk->data[stk->top--];
}

int stack_empty(stack *stk) {
    if(stk->top == -1)return 1;
    return 0;
}

int main() {
    stack qwq = stack_new();
    if(stack_empty(&qwq))puts("空");
    for(int i = 0;i < 10;++i)stack_push(&qwq, i);
    for(int i = 0;i < 11;++i)printf("%d\n", stack_pop(&qwq));
    if(stack_empty(&qwq))puts("空");
    free(qwq.data);
    getchar();getchar();
    return 0;
}