list=[90,56,67,7,8,5,4,1,2,3,4,5,6,7,]
print(sorted(list))
print(sorted(list,reverse=True))


a=sum(range(1,10))
print(f'{a}')


orders = [("A001", "手机", 5000, 2), ("A001", "手机壳", 50, 3) ,("A002", "耳机", 800, 1)]
high_price_items=[item[1] for item in orders if item[2]>100]
print(f'{high_price_items}')

items_with_total=[(item[0],item[1],item[2]*item[3])for item in orders]
print(f'{items_with_total}')

order_a001_items=[item[1] for item in orders if item[0]=="A001"and item[3]>2]
print(f'{order_a001_items}')

alerts = [f"⚠️ {item[1]} 库存不足，仅剩{item[3]}件" for item in orders if item[3]<3]
print(f'{alerts}')


j=0
for i in range(1,11):
    j=j+i
print(f'{j}')


a=[p for p in range(2,100) if 0 not in [p%d for d in range (2,int(p**0.5)+1)]]
print(f'{a}')

nums=[]
for num in range(2,100):
    pr=True
    for i in range(2,num):
        if num%i==0:
            pr=False
            break
    if pr:
        nums.append(num)
print(f'一百以内的素数：{nums}')

print('一百以内的素数为：')
for num in range(2,100):
    pr=True
    for i in range(2,num):
        if num%i==0:
            pr=False
            break
    if pr:
        print(num,end=' ')

print('\n')

print(tuple('abcdefg'))