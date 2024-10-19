numCourses=4
prerequisites=[[2,0],[1,0],[3,1],[3,2],[1,3]]

ans={}
#初始化字典树
for k in range(numCourses):ans[k]=[]
for i in prerequisites:
    ans[i[0]].append(i[1])

#检查是否满足
def cnt(qes,t):
    if ans[qes]!=[]:
        flag=False
        for p in range(len(ans[qes])):
            if ans[qes][p] not in t:
                Flag = cnt(ans[qes][p],t+[ans[qes][p]])
            else:
                return False
        return flag
    else:
        return True
for q in range(numCourses):
    if not cnt(q,[q]):
        break
else:
    print(True)
print(False)