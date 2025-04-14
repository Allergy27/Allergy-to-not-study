a = input()

flag = 0

for i in a:
    if i == "1":
        flag = 1

if flag:
    for i in a:
        if i != "2":
            print(i, end=" ")
else:
    print(a)
