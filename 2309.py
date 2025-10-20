k = sorted([int(input()) for _ in range(9)])
remain_k = sum(k) - 100
for i in range(9):
    for j in range(i+1, 9):
        if k[i] + k[j] == remain_k:
            for res in k:
                if k[i] != res and k[j] != res:
                    print(res)
            exit(0)
