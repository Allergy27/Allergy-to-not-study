numCourses=4
prerequisites=[[1,0],[2,1],[3,2],[1,3]]

ans={}
#初始化字典树
for k in range(numCourses):ans[k]=[[],[]]
for i in prerequisites:#孩子添加父亲父亲 父亲父亲添加孩子们
    fa=i[0]#父亲
    ki=i[1]#孩子
    if fa not in ans[ki][1]:#父亲不在孩子的孩子中
        #孩子添加父亲父亲
        for m in ans[fa][0]:
            if m not in ans[ki][0]:ans[ki][0].append(m)
        #父亲父亲添加孩子们
        for n in ans[fa][0]:
            for k in ans[ki][1]:#孩子孩子
                if fa in ans[k][1]:print(False)
                if k not in ans[n][1]:ans[n][1].append(k)
            if ki not in ans[n][1]:ans[n][1].append(ki)#孩子
        ans[ki][0].append(fa)
        ans[fa][1].append(ki)
    else:
        print(False)
        break
print(True)