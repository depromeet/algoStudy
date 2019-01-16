t = int(input())
dt = 3

while t > dt:
    t -= dt
    dt *= 2

print(dt - t + 1)