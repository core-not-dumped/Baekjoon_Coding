from itertools import combinations
N, M = map(int, input().split())
data = sorted(map(int, input().split()))
res = list(combinations(data, M))
for l in res:   print(*l)