import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
import os
from random import randint
x=np.arange(0.1,2.0,0.0001)
y=1/x
fig,ax=plt.subplots()
ax.plot(x,y)
plt.show()