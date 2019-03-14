import sys


def solve(n, k, arr):
    arr = sorted(arr)
    ans = sys.maxsize
    for i in range(n - k + 1):
        j = i + k - 1
        if arr[j] - arr[i] < ans:
            ans = arr[j] - arr[i]
    return ans


if __name__ == '__main__':
    n = int(input())
    k = int(input())
    arr = [int(input()) for _ in range(n)]
    print(solve(n, k, arr))
