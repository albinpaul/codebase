from itertools import permutations as p
import math
if __name__ == "__main__":
    n = 1000000
    ar = []
    for i in range(n):
        ar.append(0)

    ar[0] = 1
    ar[1] = 1

    for i in range(2, int(math.sqrt(n))+1):
        if(ar[i] == 0):
            for j in range(2*i, n, i):
                ar[j] = 1

    s = 0
    m = 0
    primelist = []
    for i in range(len(ar)):
        if(ar[i] == 0):
            primelist.append(i)

    m = 0
    g = 0
    f=0
    for k in range(len(primelist)+1, 0, -1):

        for j in range(len(primelist)-(k-1)):

            #print primelist[j:k+j]
            s = sum(primelist[j:k+j])

            cal = k
            if(s < n):
                if (ar[s] == 0 and cal > m):
                    print primelist[j:k+j]
                    g = s
                    m = cal
                    f=1
                    break
        if(f==1):
            break
    print g
    # if(s < n):
    #     if (ar[s] == 0):
    #         print primelist[j:k+j]
    #         print s
