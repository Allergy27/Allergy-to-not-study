source=["struct Node{", "    /*/ declare members;/**/", "    int size;", "    /**/int val;", "};"]
i=0
ans=[]
flag=0
for s in source:
    if s.count("/")==0 and flag==0:
        ans.append(s)
    elif s.count("/")>0 or flag==1:
        j=0
        while j <len(s)-1:
            if s[j:j+2]=="//" and flag==0:
                ans.append(s[:j])
                break
            elif s[j:j+2]=="/*" and flag==0:
                flag=1
                if s[i:j]!="":ans.append(s[i:j])
                j+=2
            elif s[j:j+2]=="*/" and flag==1:
                flag=0
                if j+2<len(s):
                    i=j+2
                    if s[i:]!="":ans[len(ans)-1]+=s[i:]
                j+=2
            j+=1
print(ans)