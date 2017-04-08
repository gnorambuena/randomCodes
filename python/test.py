import random
from collections import Counter
def generate():
      s="a"
      string="";
      while(s!=" "):
            s=random.choice("abcdefghijklmnopqrstuvwxyz ")
            string=string+s
      return string
dic={}
lis=list()
contador=0
cnt=Counter()
while contador<100000:
      r=generate()
      if r!=" ":
            lis.append(r)
            contador+=1
largos=dict()
suma=0
for word in lis:
      if len(word)-1 in largos:
            largos[len(word)-1]+=1
      else:
            largos[len(word)-1]=1
      cnt[word]+=1
print cnt.most_common(200)
for key,value in largos.iteritems():
      largos[key]=largos[key]/1000.0
print largos
