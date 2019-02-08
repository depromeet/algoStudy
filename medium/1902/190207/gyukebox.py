import sys
import time


def rotate(i, y, x, lim_y, lim_x, r):
    new_y, new_x = y, x
    cnt = 0
    leftover = r
    while cnt < r:
        if new_x == i and new_y != lim_y:
            dist = lim_y - new_y
            if leftover < dist:
                new_y += leftover
                cnt += leftover
            else:
                new_y = lim_y
                cnt += dist
                leftover -= dist
        elif new_x != lim_x and new_y == lim_y:
            dist = lim_x - new_x
            if leftover < dist:
                new_x += leftover
                cnt += leftover
            else:
                new_x = lim_x
                cnt += dist
                leftover -= dist
        elif new_x == lim_x and new_y != i:
            dist = new_y - i
            if leftover < dist:
                new_y -= leftover
                cnt += leftover
            else:
                new_y = i
                cnt += dist
                leftover -= dist
        elif new_x != i and new_y == i:
            dist = new_x - i
            if leftover < dist:
                new_x -= leftover
                cnt += leftover
            else:
                new_x = i
                cnt += dist
                leftover -= dist

    return new_y, new_x


def matrixRotation(matrix, r, h, w):
    rotated_matrix = [[0] * w for _ in range(h)]
    limit = (h if h < w else w) // 2

    # 몫 짝수 나머지 0 -> 그대로
    # 몫 짝수 나머지 n -> n번 옮김
    # 몫 홀수 나머지 0 -> 뒤집음(상하좌우 대칭)
    # 몫 홀수 나머지 n -> 뒤집고 n번 옮김
    commands = []
    for i in range(limit):
        n = (h - 2 * i) + (w - 2 * i) - 2
        quot = r // n
        rem = r % n
        commands.append([
            True if quot % 2 else False,
            rem
        ])

    for i in range(limit):
        y, x = i, i
        end_y, end_x = h - i - 1, w - i - 1

        for j in range(y, end_y + 1):
            flip, r = commands[i]
            if flip:
                curr_y, curr_x = h - 1 - j, w - 1 - x
            else:
                curr_y, curr_x = j, x
            new_y, new_x = rotate(i, curr_y, curr_x, end_y, end_x, r)
            rotated_matrix[new_y][new_x] = matrix[j][x]
        for j in range(x + 1, end_x):
            flip, r = commands[i]
            if flip:
                curr_y, curr_x = h - 1 - y, w - 1 - j
            else:
                curr_y, curr_x = y, j
            new_y, new_x = rotate(i, curr_y, curr_x, end_y, end_x, r)
            rotated_matrix[new_y][new_x] = matrix[y][j]
        for j in range(y, end_y + 1):
            flip, r = commands[i]
            if flip:
                curr_y, curr_x = h - 1 - j, w - 1 - end_x
            else:
                curr_y, curr_x = j, end_x
            new_y, new_x = rotate(i, curr_y, curr_x, end_y, end_x, r)
            rotated_matrix[new_y][new_x] = matrix[j][end_x]
        for j in range(x + 1, end_x):
            flip, r = commands[i]
            if flip:
                curr_y, curr_x = h - 1 - end_y, w - 1 - j
            else:
                curr_y, curr_x = end_y, j
            new_y, new_x = rotate(i, curr_y, curr_x, end_y, end_x, r)
            rotated_matrix[new_y][new_x] = matrix[end_y][j]

    for i in range(h):
        for j in range(w):
            print(rotated_matrix[i][j], end=' ')
        print()


if __name__ == '__main__':
    mnr = input().rstrip().split()
    m = int(mnr[0])
    n = int(mnr[1])
    r = int(mnr[2])

    matrix = []
    for _ in range(m):
        matrix.append(list(map(int, input().rstrip().split())))

    # print()
    matrixRotation(matrix, r, m, n)
