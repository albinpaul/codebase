from itertools import permutations
import numpy as np
list1= np.arange(1,10)
for i in permutations(list1):
	g=np.asarray(i)
	
	g=g.reshape(3,3)
	flag=1
	for i in range(3):
		if 15!=sum(g[:,i]):
			flag=0
			break
	if(flag==0):
		continue	
	for i in range(3):
		if 15!=sum(g[i,:]):
			flag=0
			break
	if(flag==0):
		continue

	s=0
	c = np.fliplr(g)
	if np.trace(g)==15 and np.trace(c)==15:
		
		print(','.join(map(str,g.flatten())))
	#if np.trace(g) ==15 and np.diagonal(g)==15:
	#	print(i) 