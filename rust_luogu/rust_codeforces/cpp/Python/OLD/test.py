grid=[[24,11,22,17,4],[21,16,5,12,9],[6,23,10,3,18],[15,20,1,8,13],[0,7,14,19,2]]
global n,m
n =len(grid)
def Check(x,y):
   if grid[x][y] == n**2-1:
      return True
   else:
      m=False
   if x+1<n and y+2 < n:
      if grid[x+1][y+2]==grid[x][y]+1:
         m=Check(x+1,y+2)
   if x+1<n and y-2 >= 0:
      if grid[x+1][y-2]==grid[x][y]+1:
         m=Check(x+1,y-2)
   if x+2<n and y+1 < n:
      if grid[x+2][y+1]==grid[x][y]+1:
         m=Check(x+2,y+1)
   if x+2<n and y-1 >= 0:
      if grid[x+2][y-1]==grid[x][y]+1:
         m=Check(x+2,y-1)
   if x-1>=0 and y+2 <n:
      if grid[x-1][y+2]==grid[x][y]+1:
         m=Check(x-1,y+2)
   if x-1>=0 and y-2 >= 0:
      if grid[x-1][y-2]==grid[x][y]+1:
         m=Check(x-1,y-2)
   if x-2>=0 and y+1 < n :
      if grid[x-2][y+1]==grid[x][y]+1:
         m=Check(x-2,y+1)
   if x-2>=0 and y-1 >= 0:
      if grid[x-2][y-1]==grid[x][y]+1:
         m=Check(x-2,y-1)
   return m
for i in range(n):
   for j in range(n):
         if grid[i][j]==0:
            print( Check(i,j) )