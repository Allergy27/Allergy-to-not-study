#coding=utf-8
import base64

FLAG = "flag{******HIDE*******}"

def enctypt(flag):
    result = ""
    for i in flag:
        o = ord(i)
        o-= 13
        o^= 0x2
        result += chr(o)
    bytes_result = result.encode("utf-8")
    str_result = base64.b64encode(result)
    s = str_result
    """
    flag = ''
    for i in range(12):
        flag += s[i::12]
    print(flag)
    """
#-----------------------------------------------------
print(len("WUZ1FS1UdWhQWYZGyCxRFoQdWZaiS1ZRpdky"))
p=''
res="WUZ1FS1UdWhQWYZGyCxRFoQdWZaiS1ZRpdky"
for i in range(0,len(res),3):
    p += res[i]
for i in range(1,len(res),3):
    p += res[i]
for i in range(2,len(res),3):
    p += res[i]
print(p)
res=''
for i in "[]VXlhZ&]PU!c$Pe$de'Pd!]kZr":
    o=ord(i)
    o^=0x2
    o+=13
    res+=chr(o)
print(res)
