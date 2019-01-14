a, b, c, d = sorted(map(int, input().split()))

def sum_a_to_b(a, b):
    n = b-a+1
    return (a + b)*n//2

accum = 0

t2 = d
cc = c

for _ in range(a):
    t = t2
    start = sum_a_to_b(t-cc+1, t)
    for _ in range(b):
        accum += start
        start -= t
        t -= 1
    t2 -= 1
    cc -= 1

print(accum - sum_a_to_b(c-a+1, c))