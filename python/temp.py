import math
list1=[]
cou=0
for n in range(2,20,1):
    value=math.sqrt(n)
    if(n==int(value)*(value)):
        continue
    templist=[]
    cache=set()
    condition=False
    for _ in range(3*n):#len(templist)<2*n):
       
        templist.append(int(value))
        value=value-int(value)
        m=0
        # if(len(templist)>2):
            
        #     for i in range((len(templist)-1)/2):
        #         a=templist[1:i+1]
        #         b=templist[i+1:2*i+1]
        #         f=1

        #         for j in range(len(a)):
        #             if(a[j]!=b[j]):
        #                 f=0
        #                 break
        #         if(f==1):
        #             m=max(m,len(a))

        # print(m),     
        #D=100
        # if(int(value *D) in cache):
        #     break    
        # cache.add(int(value *D))
        #print (int(value *1000000)),
        #print("value is",value),
        value=1/value
        
        #print("value is",value)
        

        
    print templist
    #print(templist,len(templist)-1)
    print(len(templist)-1)
    cou+=((len(templist)-1)%2==1)
print(cou)

