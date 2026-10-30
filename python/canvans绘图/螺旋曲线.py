#x=(w0 /32)x(cost-tsint)，y=(h0 /32)x(sint+tcost)
#式中，w0是画布宽的一半，h0是画布高的一半。t的取值范围为0～25，步长为0.01。
from tkinter import *
import math
root = Tk()
w = Canvas(root, width=600, height=600)
w.pack()
w.create_line(0, 300, 600, 300, fill="red", dash=(4, 4)) # 画红色的坐标轴线（虚线）
w.create_line(300, 0, 300, 600, fill="red", dash=(4, 4))
w0=300
h0=300
def x(t):
    x = (w0 / 32) * (math.cos(t) - t*math.sin(t))
    x+=w0    #平移x轴
    return x
def y(t):
    y = (h0 / 32) * (math.sin(t) +t* math.cos(t))
    y-=h0    #平移y轴
    y = -y    #y轴值反向
    return y
t = 0.0
while(t<25):
    w.create_line(x(t), y(t), x(t+0.01), y(t+0.01),fill="blue")
    t+=0.01
root.mainloop()