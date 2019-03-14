t = int(input())
result = [0]*t
input_range = []

for _ in range(t):
    input_range.append(tuple(map(int, input().split())))

i = 1
while i*i <= 10**9:
    for j, r in enumerate(input_range):
        if r[0] <= i*i <= r[1]:
            result[j] += 1
    i += 1

for i in result:
    print(i)