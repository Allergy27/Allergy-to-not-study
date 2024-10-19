from bisect import bisect_left
nums=[2,7,9,3,1]
k=2
def Check(maxCoin):
    cur=pre=0
    for num in nums:
        if num<=maxCoin:
            cur,pre=max(1+pre,cur),cur
        else:
            pre=cur
    return cur
print(bisect_left(range(max(nums)), k, key=Check))
        