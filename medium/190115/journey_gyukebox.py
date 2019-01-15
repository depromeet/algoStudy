def find(disjoint_set, pair):
    first, second = pair
    length = len(disjoint_set)
    indices = set()
    if not length:
        return None
    for i in range(length):
        if first in disjoint_set[i] or second in disjoint_set[i]:
            indices.add(i)
    return list(indices)


def make_disjoint_set(astronaut):
    disjoint_set = []
    for pair in astronaut:
        indices = find(disjoint_set, pair)
        if indices:
            if len(indices) > 1:
                first, second = indices
                disjoint_set[first] = \
                    disjoint_set[first] | disjoint_set[second]
                del disjoint_set[second]
            else:
                disjoint_set[indices[0]].update(pair)
        else:
            new_set = set(pair)
            disjoint_set.append(new_set)

    return disjoint_set


def journeyToMoon(n, astronaut):
    disjoint_set = make_disjoint_set(astronaut)
    total_possibilities = n * (n - 1) // 2
    num_pair_same_country = 0

    for subset in disjoint_set:
        length = len(subset)
        num_pair_same_country += length * (length - 1) // 2

    return total_possibilities - num_pair_same_country


if __name__ == '__main__':
    np = input().split()
    n = int(np[0])
    p = int(np[1])
    astronaut = []
    for _ in range(p):
        astronaut.append(list(map(int, input().rstrip().split())))
    result = journeyToMoon(n, astronaut)
    print(result)
