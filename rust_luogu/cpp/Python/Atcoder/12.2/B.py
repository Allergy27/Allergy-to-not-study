N,S,M,L=map(int,input().split())
moey=N*max(S,M,L)
for s in range(N//6+2):
    for m in range(N//8+2):
        for l in range(N//12+2):
            if s*S+m*M+l*L<moey and 6*s+8*m+12*l>=N:moey=s*S+m*M+l*L
print(moey)