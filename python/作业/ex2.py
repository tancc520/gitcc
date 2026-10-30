import random
n=int(input())
count=0
for i in range(1,n+1):
    a=random.randint(1,101)
    b=random.randint(1,101)
    c=a+b
    print(f"{a} {b}")
    print(f"{a}+{b}=",end='')
    d=int(input())
    if d==c:
        print("正确")
        count+=1
    else:
        print(f"错误！正确答案 {c}")
g=count/n*100
print("答题统计")
print(f"总题数{n}")
print(f"正确题数{count}")
print(f"错误题数{n-count}")
print(f"正确率{g:.2f}%")