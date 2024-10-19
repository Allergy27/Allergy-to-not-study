#include<stdio.h>

int main() {
    int len, width;
    printf("请输入数组的长度和宽度：");
    scanf("%d %d", &len, &width);
    printf("请输入数组的元素：\n");
    int nums[100][100];
    int qwq[100][100];
    for(int i = 0;i < len;++i) {
        for(int j = 0;j < width;++j) {
            scanf("%d", &nums[i][j]);
            qwq[j][i] = nums[i][j];
            if(i == 0 && j == 0)printf("原矩阵为：\n");
            printf("%3d", nums[i][j]);
        }
        printf("\n");
    }
    printf("转置矩阵为：\n");
    for(int i = 0;i < width;++i) {
        for(int j = 0;j < len;++j)printf("%3d", qwq[i][j]);
        printf("\n");
    }
    getchar();getchar();
    return 0;
}