from collections import Counter

c = Counter(input())
def validate(n, t1, t2):
    cnt = 0
    ans = True
    for v in c.values():
        if v - n == t1:
            continue
        elif v - n == t2:
            cnt += 1
            if cnt > 1:
                ans = False
                break
        else:
            ans = False
            break

    return ans

n1 = (sum(c.values())-1) // len(c)
n2 = (sum(c.values())-1) // (len(c)-1) if len(c)-1 != 0 else 0

if validate(n1, 0, 1) or validate(n1, 1, 0) or validate(n2, 0, 1-n2):
    print("YES")
else:
    print("NO")
