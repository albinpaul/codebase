def s(n):
	c=0
	while(n):
		c+=(n%10)
		n=n//10
		
	#print(c)
	return c

m=0
for a in range(100,0,-1):
	for b in range(100,0,-1):
		#print(a**b)
		t=s(a**b)
		if t>m:
			print(a**b)
			m=t
print(m)