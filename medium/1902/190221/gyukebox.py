def solve(n, arr):
    n1 = arr[n - 1]
    if (n - 1) % 2 == 0:
        # 마지막이 ....1111
        if n - 2 < 0:
            arr = [1, 1, n1 - 1]
        else:
            n2 = arr[n - 2]
            del arr[n - 1]
            del arr[n - 2]
            arr += [n2 - 1, 1, 1, n1 - 1]
    else:
        n2 = arr[n - 2]
        # 마지막이 ....0000
        if n - 3 < 0:
            del arr[n - 1]
            del arr[n - 2]
            if n2 == 1:
                arr = [n2, n1 + 1]
            else:
                arr = [1, n1 + 1, n2 - 1]
        else:
            n3 = arr[n - 3]
            del arr[n - 1]
            del arr[n - 2]
            del arr[n - 3]
            arr += [n3 - 1, 1, n1 + 1, n2 - 1]

    idx = 0
    n = len(arr)
    while True:
        if idx == n:
            break
        if arr[idx] == 0:
            if idx == n - 1:
                del arr[idx]
                break
            else:
                arr[idx - 1] += arr[idx + 1]
                del arr[idx + 1]
                del arr[idx]
                n -= 2
        else:
            idx += 1

    return arr


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        n = int(input())
        arr = list(map(int, input().split()))
        res = solve(n, arr)
        print(len(res))
        print(*res)
