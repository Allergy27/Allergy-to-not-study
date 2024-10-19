n = int(input())
a = 0 if n & 1 == 1 else 1
b = 1 if 4 < n <= 12 else 0
print("{} {} {} {}".format(a&b,a|b,a^b,(~a+2)&(~b+2)))