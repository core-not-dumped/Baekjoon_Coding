import sys
input = sys.stdin.readline

N = int(input())
num = list(map(int, input().split()))

pre_sum = [0]
for n in num:   pre_sum.append(n + pre_sum[-1])
sort_num = sorted(list(enumerate(num)), key=lambda x: x[1])

res, res_num = 0, 0
pres_n, pres_idx = -1, -1
for j, (i, n) in enumerate(sort_num+[(-1, -1)]):
    if pres_n != n:
        mini_sum = pre_sum[sort_num[j-1][0]+1] - pre_sum[pres_idx]
        if res < mini_sum:
            res = mini_sum
            res_num = 1
        elif res == mini_sum:
            res_num += 1
        if j != N:
            pres_n, pres_idx = n, sort_num[j][0]
print(f'{res} {res_num}')