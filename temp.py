mylist = ['x', 'x0', 'x', 'x1', 'x']
answer = -1
for item in range(len(mylist) -1, -1, -1):
    if mylist[item].isalnum():
        answer = item
        break
print(answer)