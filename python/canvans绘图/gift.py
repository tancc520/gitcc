from tkinter import *
root=Tk()
root.geometry('620x440')
mycanvas=Canvas(root)
mycanvas.pack()
photo=PhotoImage(file=r"C:\Users\ASUS\Desktop\1.gif")
mycanvas.create_image(100,100,image=photo)
root.mainloop()