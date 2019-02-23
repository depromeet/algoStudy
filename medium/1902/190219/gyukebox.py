def solve(k, s1, s2):
    n = len(s1)
    arr = [[[0, k] for _ in range(n + 1)] for _ in range(n + 1)]
    max_len = 0

    for i in range(n):
        for j in range(n):
            if s1[i] == s2[j]:
                arr[i + 1][j + 1][1] = arr[i][j][1]
                new_len = arr[i][j][0] + 1
                arr[i + 1][j + 1][0] = new_len
                if max_len < new_len:
                    max_len = new_len
            elif arr[i][j][1]:
                arr[i + 1][j + 1][1] = arr[i][j][1] - 1
                new_len = arr[i][j][0] + 1
                arr[i + 1][j + 1][0] = new_len
                if max_len < new_len:
                    max_len = new_len

    return max_len


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k, s1, s2 = input().split()
        print(solve(int(k), s1, s2))
