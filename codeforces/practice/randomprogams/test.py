import copy
def ispalindrome(n):
	string =str(n)
	for i in range( int(len(string)/2) +1 ):
		if string[i]!=string[len(string)-i-1]:
			return False
	return True

def foo(n,index):
	if index < 50:
		
		g=str(n)
		#print(g)
		if( ispalindrome(int(g))):
			return False
		else:
			return foo(int(g)+int(g[::-1]),index+1)
	else:
		return True
cou=0
for i in range(10001,0,-1):
	g=str(i)
	#print("i is ",i)
	t=copy.deepcopy(g)
	
	if( ispalindrome(int(g) )):
		pass
	else:
		if ( foo(int(g)+int(g[::-1]),1 ) ==True ):
			print(i)
			cou+=1
print(cou)