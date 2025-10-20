import sys
input = sys.stdin.readline
N = int(input())
sco = sorted(list(map(int, input().split())), reverse=True)

t_power = [1]
for i in range(N+1):
    t_power.append(t_power[-1]*2%1000000007)

res = 0
for i, s in enumerate(sco):
    res += s * (t_power[N-(i+1)]-1) - s * (t_power[i]-1)
    res %= 1000000007

print(res)