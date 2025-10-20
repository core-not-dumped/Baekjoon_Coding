import sys
input = sys.stdin.readline
N = int(input())
cor = [list(map(int, input().split())) for _ in range(N)]
x1, y1 = cor[0]
a = 0
for i in range(1, N-1):
    x2, y2 = cor[i]
    x3, y3 = cor[i+1]
    a += x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3
print(round(abs(a)/2,2))