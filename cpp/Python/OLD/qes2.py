sx = 2
sy = 4
fx = 7
fy = 7
t = 6
xderta=abs(sx-fx)
yderta=abs(sy-fy)
tim=min(xderta,yderta)
if xderta+yderta-tim < t:
    print(True)