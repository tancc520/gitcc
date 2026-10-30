from tkinter import *
root=Tk()
root.geometry('320x240')

def draw(event):
    # 画矩形
    mycanvas.create_rectangle(90,10,200,200)
    # 画椭圆，填充绿色
    mycanvas.create_oval(90,10,200,200,fill='green')
    # 画扇形
    mycanvas.create_arc(90,10,200,200,fill='pink')
    # 画多边形（三角形），前景色为蓝色，无填充色
    mycanvas.create_polygon(20,180,150,10,290,180,outline='blue',fill='')
    # 画直线
    mycanvas.create_line(10,105,290,105,fill='red')
    # 写文字，颜色为十六进制RGB字符串
    mycanvas.create_text(50,10,text='我的画布',fill="#23ADA1A2")
def delt():
    # 删除画布上的所有图形
    mycanvas.delete(ALL)

mycanvas=Canvas(root,height=200,width=300)
mycanvas.pack()
mycanvas.bind('<Button-1>',draw)
btnclr=Button(root,text='清空',command=delt)
btnclr.pack()
root.mainloop()