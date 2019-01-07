def dfs(matrix, current_point, end_point, visited, count):
    result = []
    row = len(matrix)
    col = len(matrix[0])
    y, x = current_point
    east = x + 1
    west = x - 1
    south = y + 1
    north = y - 1

    visited[y][x] = True

    if current_point == end_point:
        return count, True

    if east < col and matrix[y][east] in '.*' and not visited[y][east]:
        result.append(dfs(matrix, [y, east], end_point, visited, count))
    if west >= 0 and matrix[y][west] in '.*' and not visited[y][west]:
        result.append(dfs(matrix, [y, west], end_point, visited, count))
    if south < row and matrix[south][x] in '.*' and not visited[south][x]:
        result.append(dfs(matrix, [south, x], end_point, visited, count))
    if north >= 0 and matrix[north][x] in '.*' and not visited[north][x]:
        result.append(dfs(matrix, [north, x], end_point, visited, count))

    if result and len(result) > 1:
        for value in result:
            if value[1]:
                return value[0] + 1, True
        return count, False
    elif result:
        return result[0]
    else:
        return count, False


def find_start_and_end(matrix):
    start_point = []
    end_point = []

    row = len(matrix)
    for i in range(row):
        col = len(matrix[i])
        for j in range(col):
            if matrix[i][j] == '*':
                end_point = [i, j]
            if matrix[i][j] == 'M':
                start_point = [i, j]

    return start_point, end_point


def countLuck(matrix, k):
    row = len(matrix)
    col = len(matrix[0])
    visited = []
    for i in range(row):
        visited.append([])
        for j in range(col):
            visited[i].append(False)
    start_point, end_point = find_start_and_end(matrix)
    count, _ = dfs(matrix, start_point, end_point, visited, 0)
    return 'Impressed' if count == k else 'Oops!'
