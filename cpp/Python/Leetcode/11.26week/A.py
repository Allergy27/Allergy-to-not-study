a=[[1,2,1,2],[5,5,5,5],[6,3,6,3]]
n=len(a[0])
k=1
after =a.copy()
for i in range(len(after)):
        after[i]=after[i][k%n:]+after[i][:k%n]
print(after)
print(a)