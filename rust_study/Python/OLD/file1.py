
FLAG = "flag{******HIDE*******}"

def enctypt(s):
    s = '******HIDE*******'
    flag = ''
    for i in range(6):
        flag += s[i::6]
    print(flag)
    result  = ""
    for i in flag:
        o = ord(i)
        o^= 0x2
        o-= 5
        result += chr(o)
    print(result)

enctypt(FLAG)

print(len("_fliF-^,F`Xot+,_Xz"))
res=''
for i in "_fliF-^,F`Xot+,_Xz":
    o=ord(i)
    o+=5
    o^=0x2
    res+=chr(o)
print(res)
p=''
for i in range(0,len(res),3):
    p += res[i]
for i in range(1,len(res),3):
    p += res[i]
for i in range(2,len(res),3):
    p += res[i]
print(p)