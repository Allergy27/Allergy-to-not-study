a = []

for i in range(2):
    a.append("123" + "%d" % i)

for i in range(10):
    a.append("012" + "%d" % i)

a.append("1123")
a.append("1012")

print(len(a))
