from collections import Counter
from itertools import combinations


def validate(s):
    for i in range(1, len(s)):
        if s[i - 1] == s[i]:
            return False
    return True


n = int(input())
s = input()
alphabet = 'abcdefghijklmnopqrstuvwxyz'

answer = 0
for t1, t2 in combinations(alphabet, 2):
    result_s = ''
    for c in s:
        if c == t1 or c == t2:
            result_s += c

    if t1 in result_s and t2 in result_s and validate(result_s):
        if answer < len(result_s):
            answer = len(result_s)

print(answer)