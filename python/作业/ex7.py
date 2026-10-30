def choose(n):
    if n<2:
        return False
    for i in range(2,n):
        if n%i==0:
            return False
    return True

print("51-100中的素数有：")
for i in range(51,101):
    if choose(i)==True:
        print(i,end=' ')