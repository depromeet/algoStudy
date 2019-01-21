from collections import defaultdict

def validation(str):
    d = defaultdict(lambda: 0)

    prev = str[0]

    chk = True
    for c in str:
        if prev != c and c in d:
            chk = False
        d[c] += 1
        prev = c

    for k, v in d.items():
        if v < 2 and k != '_':
            return False
    else:
        if '_' in d:
            return True
        else:
            if not chk:
                return False

    return True

for _ in range(int(input())):
    input()
    print("YES" if validation(input()) else "NO")
