import jieba
from collections import Counter

stepwords=set()

with open ('中文停用词.txt','r',encoding='utf-8') as f:
    for word in f:
        stepwords.add(word)

with open ("二十大报告.txt",'r',encoding='utf-8') as f:
    text=f.read()

words=jieba.cut(text)


fliterwords=[
    word for word in words
    if len(word)>1 and word not in stepwords
]
wordcounts=Counter(fliterwords)
print("前往五十个词频统计：")
for word,count in wordcounts.most_common(50):
    print(f'{word}:{count}')