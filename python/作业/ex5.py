candidatep=list(map(int,input().split()))
hotp=list(map(int,input().split()))
combines=[]
for i in (candidatep):
    for j in (hotp):
        if i!=j:
            combines.append((i,j))
combines.sort(key=lambda t:(t[0],t[1]))
if len(combines)==0:
    print("None")
else:
    for p in (combines):
        print(p[0],p[1])