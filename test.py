import sys
input = sys.stdin.readline

n = int(input())

factories = list(map(int, input().split()))

answer = 0

start = 0
while start < n:

    if factories[start] == 0:
        start += 1
        continue
    cost = 0
    if start + 2 < n and factories[start] > 0 and factories[start + 1] > 0 and factories[start + 2] > 0:
        min_purchase = min(factories[start], factories[start + 1], factories[start + 2])
        cost = 7 * min_purchase
        factories[start] -= min_purchase
        factories[start + 1] -= min_purchase
        factories[start + 2] -= min_purchase

    elif start + 1 < n and factories[start] > 0 and factories[start + 1] > 0:
        min_purchase = min(factories[start], factories[start + 1])
        cost = 5 * min_purchase
        factories[start] -= min_purchase
        factories[start + 1] -= min_purchase

    elif factories[start] > 0:
        cost = 3 * factories[start]
        factories[start] = 0

    answer += cost

print(answer)