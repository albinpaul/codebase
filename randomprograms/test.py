n,m =map(int,raw_input().split())
ar=[]
for i in range(n):
    ar.append(int(raw_input(),2))
#print ar
f=1
for i in range(n):
    temp=0
    for j in range(n):
        if (i==j):
            continue
        temp|=ar[j]
    if(temp==(1<<m)-1):
        f=0
        break
if(f==1):
    print "NO"
else:
    print "YES"