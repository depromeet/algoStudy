#!/bin/python3
import os
from collections import Counter


def isValid(s):
    c = Counter(s).most_common()
    length = len(c)
    diff_cnt = 0
    for i in range(length - 1):
        _, prev_cnt = c[i]
        _, next_cnt = c[i + 1]

        diff = prev_cnt - next_cnt
        if prev_cnt - next_cnt != 0:
            if diff == 1:
                if i == 0 or i == (length - 2):
                    diff_cnt += 1
                else:
                    return 'NO'
            elif diff > 0:
                if next_cnt == 1 and i == (length - 2):
                    diff_cnt += 1
                else:
                    return 'NO'
            else:
                return 'NO'
    return 'YES' if diff_cnt <= 1 else 'NO'


if __name__ == '__main__':
    s = input()
    result = isValid(s)
    print(result)
