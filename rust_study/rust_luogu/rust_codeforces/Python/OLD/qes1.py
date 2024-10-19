nums =  [[1,3],[5,8]]
ans=[]
for i in nums:
    for j in range(i[0],i[1]+1):
        if j not in ans:
            ans.append(j)
print(len(ans))