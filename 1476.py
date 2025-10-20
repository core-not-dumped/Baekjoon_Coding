E, S, M = map(int, input().split())
E = 0 if E == 15 else E
M = 0 if M == 19 else M
while True:
    if S % 15 == E and S % 19 == M:
        print(S)
        break
    S += 28
