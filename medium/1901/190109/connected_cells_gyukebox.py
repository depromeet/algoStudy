visited = []


def dfs(matrix, row, col, current_row, current_col):
    global visited
    result = []
    east_row, east_col = current_row, current_col + 1
    west_row, west_col = current_row, current_col - 1
    south_row, south_col = current_row + 1, current_col
    north_row, north_col = current_row - 1, current_col
    ne_row, ne_col = current_row - 1, current_col + 1
    nw_row, nw_col = current_row - 1, current_col - 1
    se_row, se_col = current_row + 1, current_col + 1
    sw_row, sw_col = current_row + 1, current_col - 1

    if current_row < 0 or current_row >= row:
        return result
    if current_col < 0 or current_col >= col:
        return result
    if not matrix[current_row][current_col]:
        return result
    if visited[current_row][current_col]:
        return result

    visited[current_row][current_col] = True
    result.append((current_row, current_col))
    result += dfs(matrix, row, col, east_row, east_col) + \
        dfs(matrix, row, col, west_row, west_col) + \
        dfs(matrix, row, col, south_row, south_col) + \
        dfs(matrix, row, col, north_row, north_col) + \
        dfs(matrix, row, col, ne_row, ne_col) + \
        dfs(matrix, row, col, nw_row, nw_col) + \
        dfs(matrix, row, col, se_row, se_col) + \
        dfs(matrix, row, col, sw_row, sw_col)
    return result


def connectedCell(matrix):
    global visited
    row = len(matrix)
    col = len(matrix[0])
    visited = [[False] * col for _ in range(row)]
    sections = []
    for i in range(row):
        for j in range(col):
            if matrix[i][j] and not visited[i][j]:
                search_result = dfs(matrix, row, col, i, j)
                sections.append(search_result)
    sections = [len(section) for section in sections]
    return max(sections) if sections else 0


if __name__ == '__main__':
    n = int(input())
    m = int(input())
    matrix = []
    for _ in range(n):
        matrix.append(list(map(int, input().rstrip().split())))
    result = connectedCell(matrix)
    print(result)
