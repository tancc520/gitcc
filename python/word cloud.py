import wordcloud
from matplotlib import pyplot as plt
w=wordcloud.WordCloud(font_path="simfang.ttf")
path="aa.txt.crdownload"
txt=open(path,'r',encoding="utf-8").read()
nw=w.generate(txt)
plt.imshow(nw)
plt.show()