#"""
from random import randint as RD
a={"world":1,2:"hello"}
#Key Values
for i in a.values():
    print(i)
for i in a.keys():
    print(i)
#split()

q=list(map(str,input().split()))#以空格为分割点
for i in q:
    print(i,end=" ")
print()
q=list(map(str,input().split(',')))#以逗号为分割点
for i in q:
    print(i,end=" ")
print()

#自定义函数:
def qwq(a,b):
    return a+b
print(qwq(a[2]," world"))
#库函数:
qaq=[0 for i in range(10)]
print(qaq)
for i in range(10):qaq[i]=RD(1,100)
print(qaq)
#变量本身带方法？
class qvq:#创建对象
    def hello():#方法
        print("Hello world!!!")
qvq.hello()#调用成员函数/方法
print("hEllO world".upper().lower())#转大小写
#lstrip()删除左边空白
a="    我旁边有空白      "#然而没有
a=a.lstrip()[::-1].lstrip()[::-1]#两次反转把两边空白都删了
print(a)
#形参和实参:
def add(mqw):
    return mqw+1#行吧，字典反正可以
a=[1,1,5,1,61,236,17,1,7]
a.append("qwq")
print(a)
a.pop()
a.sort()#永久改变
print(sorted(a))#返回排序后的值

#翻转列表
a=[1,1,6,545,73,8,36,83,9,39,3,93,12]
print(a)
print(a[::-1])


#_______________法1
a=input().lower()
b=[]
flag=0
for i in a:
    if i not in b:b.append(i)
    else:
        flag=1
        break
print(flag==0)
#_______________法2
a={}
b=input().lower()
flag=0
for i in range(26):
    a[chr(97+i)]=0
for i in b:
    a[i]+=1
    if a[i]>1:#判断字典里有无重复
        flag=1
        break
print(flag==0)
#_______________法3
a=input().lower()
b=[]
flag=0
for i in a:
    b.append(ord(i))
b.sort()
for i in range(1,len(b)):
    if b[i-1]==b[i]:#列表中出现重复
        flag=1
        break
print(flag==0)
#——————————————————————法4
#set,不写了
#_____________________法5
a=input().lower()
flag=0
for i in range(len(a)):
    if a[i] in a[:i]+a[i+1:]:#成员函数判断是否在除自己以外的位置出现
        flag=1
        break        
print(flag==0)
#"""