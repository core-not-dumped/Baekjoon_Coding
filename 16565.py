from math import comb
N = int(input())
if N < 4:   print(0);exit(0)

def fcard_n_line_not_exist(line_num, remain_n):
    if remain_n == 0:   return 1
    if remain_n in [1,2,3]: return comb(line_num*4, remain_n)
    if remain_n > line_num * 3: return 0

    total = comb(line_num*4, remain_n)
    remove = 0
    for i in range(1, remain_n//4+1):
        remove += comb(line_num, i) * fcard_n_line_not_exist(line_num-i, remain_n - 4*i)
    return (total - remove)%10007

def get_res(max_line, N):
    return (comb(max_line*4, N) - fcard_n_line_not_exist(max_line, N))%10007

print(get_res(13, N))
