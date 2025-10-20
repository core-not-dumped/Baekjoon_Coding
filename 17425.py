import sys
input = sys.stdin.read
print = sys.stdout.write
data = input().split()
max_size = 1000001
sum_list = [0] * max_size
for i in range(1, max_size):
    for j in range(i, max_size, i):
        sum_list[j] += i
for i in range(1, max_size):    sum_list[i] += sum_list[i-1]
res = [str(sum_list[int(d)]) for d in data[1:]]
print('\n'.join(res) + '\n')