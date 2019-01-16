for _ in range(int(input())):
    s_input = input()
    s = 0
    for a in map(int, list(s_input)):
        if a != 0 and int(s_input) % a == 0:
            s += 1

    print(s)