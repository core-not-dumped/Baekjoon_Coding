from itertools import permutations
N, M = map(int, input().split())
data = sorted(map(int, input().split()))
res = list(permutations(data, M))
for l in res:   print(*l)