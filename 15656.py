from itertools import product
N, M = map(int, input().split())
data = sorted(map(int, input().split()))

def comb(pres_list:list):
    if len(pres_list) == M:
        res.append(pres_list[:])
        return
    for d in data:
        if (not pres_list) or d >= pres_list[-1]:
            pres_list.append(d)
            comb(pres_list)
            pres_list.pop()

res = []
comb([])
for l in res:   print(*l)