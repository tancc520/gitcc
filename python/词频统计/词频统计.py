import jieba as jb 
f=open(r"词频统计\荷塘月色.txt",'r',encoding='UTF-8')
e=f.read()
f.close()
art=jb.lcut(e)
dic={}
for word in art:
    if word not in dic:
        dic[word]=1
    else:
        dic[word]+=1
swd=sorted(list(dic.items()),key=lambda x:x[1],reverse=False)
f1=open(r"词频统计\中文虚词列表.txt",'r',encoding='UTF-8')
art2=f1.read()
f1.close()
for word,times in swd:
    if word not in art2:
        print(word,times)       