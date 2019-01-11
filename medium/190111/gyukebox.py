#!/bin/python3
# Complete the biggerIsGreater function below.


def biggerIsGreater(w):
    length = len(w)
    for i in range(length - 2, -1, -1):
        if w[i] < w[i + 1]:
            tmp = w[i:]
            tmp_idx = tmp[0]
            tmp_sorted = sorted(tmp)
            for j in range(length - i):
                if tmp_sorted[j] > tmp_idx:
                    next_idx = j
                    next_letter = tmp_sorted[next_idx]
                    break
            del tmp_sorted[next_idx]
            # print(tmp, tmp_idx, tmp_sorted, next_idx, next_letter)
            return w[:i] + next_letter + ''.join(tmp_sorted)
    else:
        return 'no answer'


if __name__ == '__main__':
    T = int(input())
    for T_itr in range(T):
        w = input()
        result = biggerIsGreater(w)
        print(result)
