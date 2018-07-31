N = int( input() )
A = [ int(x) for x in input().split() ]
 
from collections import defaultdict
inside = defaultdict(int)
 
answer = 1
r = 0
# two pointer implementation of the 

for l in range(N):
    if l > 0:
        inside[ A[l-1] ] -= 1
        if inside[ A[l-1] ] == 0: del inside[ A[l-1] ]
    while r < N and (len(inside) < 2 or A[r] in inside):
        inside[ A[r] ] += 1
        r += 1
    answer = max( answer, r-l )
 
print(answer) 