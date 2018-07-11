def foo(L):
    new = []
    n=len(L)
    for _ in range(n-1):
        for i in range(1,len(L)):
            new.append(L[i]^L[i-1])
        print new
        L=new
        new=[]
    if len(L)==1:
        return L[0]
    else:
        print "Error"
print  foo([1 ,2 ,4 ,8 ,16 ,32, 64])
