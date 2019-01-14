d, m, y = map(int, input().split())
d2, m2, y2 = map(int, input().split())

fine = 0
if y - y2 > 0:
    fine += (y-y2)*10000
elif y - y2 == 0 and m - m2 > 0:
    fine += (m-m2)*500
elif y - y2 == 0 and m - m2 == 0 and d - d2 > 0:
    fine += (d-d2)*15

print(fine)