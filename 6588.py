import sys
import io, os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
is_prime = [True] * 999998
for d in range(3, 1000, 2):
    if is_prime[d]:
        for idx in range(d*d, 999998, d*2):
            is_prime[idx] = False
primes = [i for i in range(3, 999984, 2) if is_prime[i]]
while True:
    n = int(input())
    if not n:   break
    for p in primes:
        if is_prime[n - p]:
            sys.stdout.write(f'{n} = {p} + {n-p}\n')
            break
