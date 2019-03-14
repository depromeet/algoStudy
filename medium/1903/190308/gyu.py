import sys


def solve(n, arr):
    sum_subarr = -sys.maxsize - 1
    tmp = 0
    sum_subseq = 0

    for i in range(n):
        tmp = tmp + arr[i]
        if sum_subarr < tmp:
            sum_subarr = tmp

        if tmp < 0:
            tmp = 0

        if arr[i] > 0:
            sum_subseq += arr[i]

    if sum_subarr < 0 and sum_subseq == 0:
        sum_subseq = sum_subarr

    return sum_subarr, sum_subseq


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        print(*solve(n, arr))
