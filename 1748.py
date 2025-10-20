n = int(input())
res = 0
t, p1, p2 = 10, 1, 9
while True:
    if t <= n:
        res += p1 * p2
    else:
        res += p1 * (n - t//10 + 1)
        print(res)
        break
    t *= 10
    p1 += 1
    p2 *= 10