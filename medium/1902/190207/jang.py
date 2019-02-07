def matrix_rotation():
    n, m, rot = map(int, input().split())
    h, w = n, m
    matrix = [list(map(int, input().split())) for _ in range(n)]

    pivot = 0
    while pivot < (min(h, w) // 2):
        d = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        l_len = (n * 2 + m * 2 - 4)

        l = [0] * l_len
        r, c = 0, 0
        di = 0
        for k in range(l_len):
            l[k] = matrix[pivot + r][pivot + c]

            dr = r + d[di][0]
            dc = c + d[di][1]

            if 0 > dr or n <= dr or 0 > dc or m <= dc:  # r이나 c가 범위를 벗어나면
                di += 1  # 방향 전환

            r += d[di][0]
            c += d[di][1]

        di = 0
        offset = (rot % l_len)
        for k in range(l_len):
            matrix[pivot + r][pivot + c] = l[(k + offset) % l_len]

            dr = r + d[di][0]
            dc = c + d[di][1]

            if 0 > dr or n <= dr or 0 > dc or m <= dc:  # r이나 c가 범위를 벗어나면
                di += 1  # 방향 전환

            r += d[di][0]
            c += d[di][1]

        n -= 2
        m -= 2
        pivot += 1

    for m in matrix:
        print(*m)


matrix_rotation()