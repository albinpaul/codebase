import math
ll = 200000000
ar=[0]*ll
ar[0]=1
ar[1]=1
for i in range(2,int(math.sqrt(ll)) +1):
    if(ar[i]==0):
        for j in range(2*i,ll,i): 
            ar[j]=1


def foo(n,i):
    i-=1
    return n+i*(n-1)+(i*(i+1)//2)*8 
primele=0
coun=1

for i in range(1,10000):
    a=foo(3,i)
    b=foo(5,i)
    c=foo(7,i)
    d=foo(9,i)
    print(a,b,c,d)
    if(a>ll or b>ll or c>ll or d>ll ):
        print("Increase the size")
        break
    coun+=4
    if (ar[a]==0):
        primele+=1
    if (ar[b]==0):
        primele+=1
    if (ar[c]==0):
        primele+=1
    if (ar[d]==0):
        primele+=1
    print(primele/coun)
    if(primele/coun<0.1):
        print("The answer is ",2*i+1)
        break