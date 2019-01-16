s1 = input()
s2 = input()
k = int(input())

i = 0
while i < len(s1) and i < len(s2):
    if s1[i] != s2[i]:
        break
    i += 1

m = (len(s1) - i) + (len(s2) - i)

if m == k:
    print("Yes")
elif k > m:
    if (k-m) % 2 == 0:
        print("Yes")
    elif k >= (len(s1) + len(s2)):
        print("Yes")
    else:
        print("No")
else:
    print("No")
