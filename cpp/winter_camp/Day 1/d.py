s = input()
for x in s:
    if x in ["B", "C", "D", "E", "F", "G", "J", "K", "L", "N", "P", "Q", "R", "S", "Z"]:
        print("NO")
        break
else:
    if s == s[::-1]:
        print("YES")
    else:
        print("NO")
