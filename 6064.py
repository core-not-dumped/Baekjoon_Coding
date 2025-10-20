T = int(input())
for _ in range(T):
    M, N, x, y = map(int, input().split())
    year = x
    for i in range(N):
        if (year - 1) % N + 1 == y:
            print(year)
            break
        year += M
    else:
        print(-1)