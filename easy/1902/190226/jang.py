def get_result(s):
    if len(s) == 1:
        return "NO"

    for i in range(len(s) - 1):
        start = int(s[:i + 1])
        current = start
        next_point = i + 1
        while next_point <= len(s):
            next_number = current + 1
            next_offset = next_point + len(str(next_number))

            if s[next_point:next_offset] and next_number != int(s[next_point:next_offset]):
                break

            current = next_number
            next_point = next_offset

        if next_point > len(s):
            return "YES " + str(start)

    return "NO"


for _ in range(int(input())):
    s = input()
    print(get_result(s))
