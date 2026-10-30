import matplotlib.pyplot as plt
import matplotlib
import numpy as np
myfont=matplotlib.font_manager.FontProperties(fname='C:/Windows/Fonts/STSONG.TTF')
matplotlib.rcParams['axes.unicode_minus'] = False 
x = [0, 1, 2, 4, 5, 6]
w = [3, 2, 5, 2, 3, 2]
y = [1, 2, 3, 2, 4, 1]
z = [1, 2, 3, 4, 5, 6]
plt.plot(x,w,'b',x,y,'--*r',x,z,'-.+g')
plt.xlabel("x轴",fontproperties=myfont)
plt.ylabel("w、y、z轴",fontproperties=myfont)
plt.title("折线图",fontsize=20,fontproperties=myfont)
plt.show()