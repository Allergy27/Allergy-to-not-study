# ⭐课上最后出现的问题：
---
## 了解scanf()
- 这个问题其实不难，我们只需要了解一下`scanf()`这个函数的一个小特性就行了，`scanf()`其实是不会读入你的空白符的，这就导致你在换行的时候最后的`\n`是没有被读入程序中的，而`gets()`非常暴力，连空白符也会读入进去的，所以出问题就在这个特性上
- 我们不妨用一个图来加深理解一下：
![](https://gitee.com/deer-b/picture/raw/master/img/20231127172720.png)
假设这个是我们命令行的缓冲区，当我们输入以下内容时：`\n\n\n\n\n\0\0\01`，代码`scanf("%d",&x)`只会读取最后的1（`\0`其实是什么都没有,我在这里假装它是空格
![](https://gitee.com/deer-b/picture/raw/master/img/20231127173303.png)
![](https://gitee.com/deer-b/picture/raw/master/img/20231127173337.png)
结果我们发现x是1，也就是说所有的空白符都被忽略了，那么在缓冲区里头发生了什么呢？

一开始是这样的(当然其实\n读进来就被弹出了)
![](https://gitee.com/deer-b/picture/raw/master/img/20231127174247.png)
接着当我们输入了1并敲下空格时`scanf()`开始读取并忽略了其中的空白符：
![](https://gitee.com/deer-b/picture/raw/master/img/20231127174746.png)
一直到了第一个不为空白符的数字1（其实`scanf()`还会接着找下去直到遇见空白符,不过在遇到回车前我们没有往缓冲器添加任何字符。

![](https://gitee.com/deer-b/picture/raw/master/img/20231127174831.png)
然后，缓冲区中什么都没有了吗？不是的，这里面还有一个回车，这是我们刚刚为了向缓存区中输入数据而输入的：
![](https://gitee.com/deer-b/picture/raw/master/img/20231127174911.png)
于是在`scanf()`操作过后缓冲区就变成了这样：
![](https://gitee.com/deer-b/picture/raw/master/img/20231127174434.png)
这种情况就比较不理想了，如果接下来遇到的是`scanf()`，那没有任何问题，因为它会忽略掉空白符，但是`gets()`就不一样了，`gets()`不会忽略空白符，而且，更糟糕的是，他一旦检测到第一个换行符后，就会读取，那么我们假设现在输入了20230001，缓冲区的情况就会变成这样:
![](https://gitee.com/deer-b/picture/raw/master/img/20231127175602.png)
虽然我们想让`gets()`读取的是20230001，但是很显然，在它遇到第一个回车之后，什么也没读取到，于是`gets()`传输的值是`\0`（我们可以在调试界面看到：
![](https://gitee.com/deer-b/picture/raw/master/img/20231127175855.png)
而我们的输入长这样：
![](https://gitee.com/deer-b/picture/raw/master/img/20231127175924.png)
很显然res并没能读取20230001，而是读取了空白符回车

---
## 解决问题
- 于是在了解了`scanf()`和缓冲区的相关知识后，我们可以考虑原问题了：
![](https://gitee.com/deer-b/picture/raw/master/img/20231127180157.png)
这段代码可能有些许不一样（下课就忘了）但是存在的问题是一样的:
- 在我们输入测试样例后，程序给出了这样的输出：
![](https://gitee.com/deer-b/picture/raw/master/img/20231127180353.png)
- **这下是不是想起来了！** 我们的程序看来确实有很大的问题（但最后我们会发现其实不大）第二个的输出怎么会是0呢，还有后面的怎么也不能是2023004啊，这不是学号吗，难道输出错了，输出成学号了？其实不是的，原因其实就是我们上面讲的`scanf()`会留下换行符而不是读掉它，那这种情况下如果和`gets()`连用就会导致出现异常（所以其实我的VScode要求我使用`fgets()`等，这是它的警告信息：
![](https://gitee.com/deer-b/picture/raw/master/img/20231127180503.png)
![](https://gitee.com/deer-b/picture/raw/master/img/20231127180911.png)
-  那么正确的代码应该是在`scanf()`后面添加一个`getchar()`，来读取换行符避免`gets()`直接读入`\0`，进而导致程序后面的出错：
```C
#include<stdio.h>

typedef struct stuInfo {
    char Num[10];
    char Name[10];
    float Eng, Math, Chin;
}stu;

int main() {
    stu qwq[5];
    float sum[5];
    for(int i = 0;i < 5;++i) {
        gets(qwq[i].Num);
        gets(qwq[i].Name);
        scanf("%f%f%f", &qwq[i].Eng, &qwq[i].Math, &qwq[i].Chin);
        char s = getchar(); //我们需要加上这个来帮助scanf读掉缓存区的的\n
        sum[i] = qwq[i].Eng + qwq[i].Math + qwq[i].Chin;
    }
    for(int i = 0;i < 5;++i)printf("%f\t", sum[i]);
    getchar();getchar();
    return 0;
}
```

**那么现在就让我们来运行一下这个程序吧：**
![](https://gitee.com/deer-b/picture/raw/master/img/20231127181431.png)

**完美！完结撒花~**