from __future__ import print_function
import sys
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

def foo(n):
	while n%2==0 :
		n=n/2
	while n%5==0 :
		n=n/5
	if n==1:
		return 0
	i=1
	while (10**i-1)%n!=0:
		i+=1
	return i
# 100x -x=  
def fun(n):
	return 1/(n*1.0)
# m=0
# for i in range(1,26):
# 	print(fun(i),i)
# p=0
# for i in range(1,1000):
# 	g=foo(i)

# 	if g>m:
# 		p=i
# 		m=g
# print(p)

import os 
f=open("help.txt ",'w')
f.write(help(dir(os)))
f.close()
print(help(dir(os)))
