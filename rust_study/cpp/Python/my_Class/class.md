目录：
[TOC]

# Python教学
[题单](https://www.luogu.com.cn/training/500268#problems)
## 第一个程序
```Python
print("Hello_world")
```
## 变量
首先认识一下 Python 最基础的东西: 变量
```Python
name = "Alice"
age = 25
is_student = True
```
这段程序创建了三个变量，在Python中变量的类型会由编译器自行推断，例如`name`是字符串，`age`是整型，`is_student`是布尔类型，这些变量就类似我们在列方程解决实际问题时创建的未知数，用来进行各种运算或者存储数值
## 输出
Python 中的输出使用的是`print()`函数，其用法像这样：
```python
print("My name is", name)
print("I am", age, "years old")
```
而其中的`name`和`age`就是变量，使得程序输出`name`和`age`的值而不是固定的某个值。
`print()`中的不同变量之间用`,`隔开，而每个`,`都对应一个空格，要去掉这些空格，我们需要设置`print()`的格式，使用控制符`sep=''`例如：`print("...",sep='')`，同时，其行尾自动输出一个换行符，要想不输出换行符，我们就需要使用`end=''`

## 读输入
Python 中读输入需要`input()`来实现，做题时通常需要单行输入多个变量，这个时候我们可以使用`split()`将其分割成为元组，接着用`map()`将其中元素全部转换成int型或者别的什么型，必要时还可以用`list()`转换为列表，使用示例如下：
```Python
a,b=map(int,input().split()) #读取两个整型输入
nums=list(map(int,input().split())) #读取一行以空格分割的整型并存进列表
```

## 分支结构
Python中分支结构语法见示例：
```Python
if is_student:
    print("yes")
else:
    print("no")
```

## 循环
Python中for循环由以下部分构成：
```
for 循环变量 in 序列:
    循环体
```
Python中while循环由以下部分构成：
```
while 条件成立:
    循环体
```
其中循环体指的是不断进行的操作，for循环有着确定的执行次数，而while循环则是当条件成立就一直进行下去
例如以下两段代码都可以实现输出一个5X5的`*`正方形
```python
for i in range(5):
    print("*"*5)
i=0
while i<5:
    print("*"*5)
    i+=1
```

暂时这些，可以做做看题单的题