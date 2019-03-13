t1, t2, n = map(int, input().split())
ts = [t1, t2]+[0]*18

for i in range(2,n):
    ts[i] = ts[i-2] + ts[i-1]**2
    if i == n-1: print(ts[i])
print(ts)
