a,b,c= map(int,input().split())
d = a^b^c
print(d if d in [a,b,c] else 0)