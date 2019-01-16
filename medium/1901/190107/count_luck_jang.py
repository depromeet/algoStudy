result = 0

def check_out_of_bound(r, c, forest):
    return 0 > r or r >= len(forest) or 0 > c or c >= len(forest[0]) or forest[r][c] == 'X' or forest[r][c] == '1'

# 앞으로 나아가는 길이 갈림길이면 True를 반환
def is_splited_way(r, c, forest, ds):
    cnt = 0
    for d in ds:
        dr = r + d[0]
        dc = c + d[1]
        if not check_out_of_bound(dr, dc, forest) and (forest[dr][dc] == '.' or forest[dr][dc] == '*'):
            cnt += 1
            if cnt >= 2:
                return True
    return False


def find_portkey(r, c, forest):
    global result
    if check_out_of_bound(r, c, forest):
        return False

    if forest[r][c] == '*':
        return True

    ds = [[1, 0], [-1, 0], [0, -1], [0, 1]]

    if is_splited_way(r, c, forest, ds):
        forest[r][c] = '1'
    else:
        forest[r][c] = 'X'

    for d in ds:
        dr = r+d[0]
        dc = c+d[1]

        if find_portkey(dr, dc, forest):
            if forest[r][c] == '1':
                result += 1
            return True

    return False


def start():
    global result
    for _ in range(int(input())):
        result = 0
        n, m = map(int, input().split())
        forest = []

        sr, sc = 0, 0
        for r in range(n):
            forest.append(list(input()))
            try:
                c = forest[-1].index('M')
                sr, sc = r, c
            except:
                pass

        find_portkey(sr, sc, forest)

        k = int(input())
        print("Impressed" if result == k else "Oops!")

start()


