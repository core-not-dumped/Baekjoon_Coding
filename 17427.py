n = int(input())

s = 0
i = 1
while i <= n:
    q = n // i
    j = n // q
    s += q * (i + j) * (j - i + 1) // 2
    i = j + 1

print(s)