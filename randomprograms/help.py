def fut(n):
    print
    print n
    while(n!=-1):
        print bin(n)
        n=((n&(n+1))-1)
    print bin(n),
def foo(n):
    for i in range(n):
        fut(i)
foo(100)