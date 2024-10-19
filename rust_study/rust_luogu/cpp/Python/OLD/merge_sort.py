nums=[1,1]
def merge_sort(nums,idx):
    p,q,r,a,b = 0,idx,len(nums),0,0
    L,R=nums[p:q],nums[q:r]
    for i in range(p,r):
        if a==q-p:
            nums[i]=R[b]
            b+=1
        elif b==r-q:
            nums[i]=L[a]
            a+=1
        elif L[a]>R[b]:
            nums[i]=L[a]
            a+=1
        else:
            nums[i]=R[b]
            b+=1
k=0 # 计数
s=sum(nums)/2 # 判断结束条件
Del=0 # 删去的和
nums=sorted(nums)[::-1] # 原先是无序的，因此直接排序就是最优解
idx=0
while Del<s:#终结条件
    nums[idx]/=2
    Del+=nums[idx]
    k+=1
    if Del>= s:break
    if nums[idx]<nums[idx+1] :idx+=1
    if nums[idx]<nums[0]:
        merge_sort(nums,idx)
        idx=0
print(k)