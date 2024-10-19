grid =[[1,3,0],[1,0,0],[1,0,3]]
ans=[]
def run(x,y,t,A):
    A.append([x,y])
    if grid[x][y] > 1:
        grid[x][y]-=1
        ans.append(t)
        return 0
    if x-1>=0 and [x-1,y] not in A:
        run(x-1,y,t+1,A)
    if x+1<3 and [x+1,y] not in A:
        run(x+1,y,t+1,A)
    if y-1>=0 and [x,y-1] not in A:
        run(x,y-1,t+1,A)
    if y+1<3 and [x,y+1] not in A:
        run(x,y+1,t+1,A)
for i in range(3):
    for j in range(3):
        if grid[i][j] == 0:
            grid[i][j] = 1
            run(i,j,0,[])
print(ans)