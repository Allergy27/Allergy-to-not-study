n = "7355608"
ans = 0
for i in n:
    ans += bin(int(i)).count("1")
print(ans)
