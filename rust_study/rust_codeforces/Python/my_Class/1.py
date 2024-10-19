a,b=map(int,input().split())
go_time = 470 - a // b - (a % b > 0)
if go_time<0:go_time+=1440
print("{:02}:{:02}".format(go_time//60,go_time%60))