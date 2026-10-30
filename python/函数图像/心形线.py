import math 
import turtle
def drawline(ttl,x1,y1,x2,y2):
    ttl.penup()
    ttl.goto(x1,y1)
    ttl.pendown()
    ttl.goto(x2,y2)
    ttl.penup()
def drawF(ttl,begin,end,step,w0,h0):
    t=begin
    while t<end:
        if t>begin:
            ttl.pendown()
        x=(w0/4)*(-2*math.sin(t)+math.sin(2*t))
        y=(h0/4)*(-2*math.cos(t)+math.cos(2*t))
        ttl.goto(x,y)
        t+=step
    ttl.penup()
def main():
    turtle.setup(800,800,0,0)
    ttl=turtle.Turtle()
    drawline(ttl,-400,0,400,0)
    drawline(ttl,0,400,0,-400)
    ttl.pencolor('red')
    ttl.pensize(5)
    drawF(ttl,0,2*math.pi,0.01,400,400)
    turtle.done()

if __name__=="__main__":
    main()