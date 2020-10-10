from itertools import permutations as p

n = 3      #This can be change

permu_lst = [i for i in p(range(1, n+1)]

for permutation in permu_lst:
    print(*permutation)
