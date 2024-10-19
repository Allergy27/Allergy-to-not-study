nums=[1,1,1]
k=0
s=sum(nums)/2
Del=0
nums.sort()
if len(nums)==1:print(1)
while Del<s:#终结条件
    nums.sort()
    t=nums[-1]/2
    p=0
    q=len(nums)
    while p<=q:#对分查找
        m=(p+q)//2
        if nums[m]<t and nums[m+1]>t:
            break
        elif nums[m]<t:
            p=m+1
        else:
            q=m-1
    for i in range(len(nums)-1,m,-1):#减半后重组
        k+=1
        nums[i]=nums[i]/2
        Del+=nums[i]
        if Del >= s:#当减出比目标情况大时结束
            break
print(k)