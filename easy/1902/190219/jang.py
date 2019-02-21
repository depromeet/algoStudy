n = int(input())
s = input()

check_field = ["0123456789", "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "!@#$%^&*()-+"]
check = [1]*4

for c in s:
    for i in range(4):
        if c in check_field[i]:
            check[i] = 0

if n < 6:
    d = sum(check) - (6-n)
    if d < 0:
        d = 0
    print(6-n + d)
else:
    print(sum(check))

