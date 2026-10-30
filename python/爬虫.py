import html
import urllib.request
import re
def gethelp(url):
    h=urllib.request.urlopen(url)
    html=h.read()
    return html
def download(html):
    reg=r'src=".*?\.(?:jpg|png)"'
    imgre=re.compile(reg)
    urls=imgre.findall(html)
    x=0
    for url in urls: # 遍历匹配到的每个图片标签字符串 # 提取 src="..." 中的实际URL（去掉 src=" 和末尾的 "）
        img_url = url[5:-1] # 切片操作：url字符串前5个字符是'src="'，最后一个字符是'"'，去掉后得到中间的URL # 补全完整URL（如果是相对路径）
        if img_url.startswith('/'): # 如果图片URL以斜杠开头，说明是相对于网站根目录的相对路径
                img_url = 'http://www.ecust.edu.cn' + img_url # 拼接网站域名，得到完整URL # 获取文件扩展名（jpg 或 png）
        ext = img_url.split('.')[-1] # 按点分割URL取最后一部分作为文件扩展名（如jpg或png） # 下载图片并保存到本地，文件名格式：编号.扩展名
        urllib.request.urlretrieve(img_url, 'f:/lenovo/%s.%s' % (x, ext)) # 使用urlretrieve下载图片并保存到f:/lenovo/目录
        x += 1 # 计数器加1，为下一张图片准备新编号

def main(): # 定义主函数，程序入口 # 第一步先要实现能够访问到网页
    html = gethelp('http://www.ecust.edu.cn').decode('UTF-8') # 调用getHttp获取华东理工大学官网首页的HTML字节串，用UTF-8解码为字符串
''' 注：应根据网页的实际编码选择decode编码。若不加decode会报byte-like object非string错误'''
    download(html) # 调用downloadImg函数，传入解码后的HTML字符串，下载页面中的图片
if __name__ == '__main__': # 判断当前脚本是否作为主程序运行（而非被导入为模块）
        main() # 如果是，则执行main函数import urllib.request
import re
def gethelp(url):
    h=urllib.request.urlopen(url)
    html=h.read()
    return html
def download(html):
    reg=r'src=".*?\.(?:jpg|png)"'
    imgre=re.compile(reg)
    urls=imgre.findall(html)
    x=0
    for url in urls: # 遍历匹配到的每个图片标签字符串 # 提取 src="..." 中的实际URL（去掉 src=" 和末尾的 "）
        img_url = url[5:-1] # 切片操作：url字符串前5个字符是'src="'，最后一个字符是'"'，去掉后得到中间的URL # 补全完整URL（如果是相对路径）
        if img_url.startswith('/'): # 如果图片URL以斜杠开头，说明是相对于网站根目录的相对路径
                img_url = 'http://www.ecust.edu.cn' + img_url # 拼接网站域名，得到完整URL # 获取文件扩展名（jpg 或 png）
        ext = img_url.split('.')[-1] # 按点分割URL取最后一部分作为文件扩展名（如jpg或png） # 下载图片并保存到本地，文件名格式：编号.扩展名
        urllib.request.urlretrieve(img_url, 'f:/lenovo/%s.%s' % (x, ext)) # 使用urlretrieve下载图片并保存到f:/lenovo/目录
        x += 1 # 计数器加1，为下一张图片准备新编号

def main(): # 定义主函数，程序入口 # 第一步先要实现能够访问到网页
    html = gethelp('http://www.ecust.edu.cn').decode('UTF-8') # 调用getHttp获取华东理工大学官网首页的HTML字节串，用UTF-8解码为字符串
''' 注：应根据网页的实际编码选择decode编码。若不加decode会报byte-like object非string错误'''
download(html) # 调用downloadImg函数，传入解码后的HTML字符串，下载页面中的图片

if __name__ == '__main__': # 判断当前脚本是否作为主程序运行（而非被导入为模块）
        main() # 如果是，则执行main函数import urllib.request
