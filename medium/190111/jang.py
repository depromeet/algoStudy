def next_permutation(s):
    i = len(s)-1

    while i > 0 and s[i-1] >= s[i]:
        i -= 1

    if i <= 0:
        return "no answer"

    j = len(s)-1
    while i-1 < j:
        if s[i-1] < s[j]:
            break
        j -= 1

    sl = list(s)
    sl[i-1], sl[j] = sl[j], sl[i-1]
    return ''.join(sl[:i] + list(reversed(sl[i:])))

for _ in range(int(input())):
    print(next_permutation(input()))

