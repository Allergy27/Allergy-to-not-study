import random as rd

def red_get(gold,n):
    ans=[]
    for i in range(n-1):
        get= rd.uniform(0,gold/(n-i)*2)
        gold-=round(get,2)
        ans.append(round(get,2))
    ans.append(round(gold,2))
    return ans

for (i,x) in enumerate(red_get(50,10)):
    print("第{}位群友抽中了{}元".format(i+1,x))

