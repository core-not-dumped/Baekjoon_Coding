import sys
input = sys.stdin.readline
N = int(input())
s = [0]
for i in range(1, 80001):   s.append(s[i-1] + (i if i % 3 == 0 or i % 7 == 0 else 0))
data = map(int, input().split())
for i in data:  print(s[i])