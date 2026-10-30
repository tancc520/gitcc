import re
p=re.compile('^[a-zA-Z0-9]{1,10}@[a=zA-Z0-9].(com|org)$',re.I)
while True:
    s=input('请输入测试。。:\n')
    if s=='0':
        break
    m=p.match(s)
    if m:
        print('%s符合规则'%s)
    else:
        print('%s不符合规则'%s)