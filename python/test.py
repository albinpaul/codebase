from pprint import pprint
# with open('p059_cipher.txt','r') as f:
#     content=f.read()
#     arr =list(map(int,content.split(',')))
#     #pprint(arr)
#     for i in range(ord('a'),ord('z')+1):
#         for j in range(ord('a'),ord('z')+1):
#             for k in range(ord('a'),ord('z')+1):
#                 temp =[0]*len(arr)
#                 #print(i,j,k)
#                 for index in range(0,len(arr),3):
#                     if(index<len(arr)):
#                         temp[index] = arr[index]^i
#                     if(index+1<len(arr)):
#                         temp[index+1] = arr[index+1]^j
#                     if(index+2<len(arr)):
#                         temp[index+2] = arr[index+2]^k
#                 print(''.join(map(chr,temp)))

with open('required.txt','r') as  f:
    content=f.read()
    s=0
    for i in content:
        s+=ord(i)
    print (s)

