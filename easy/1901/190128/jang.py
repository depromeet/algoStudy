def pangram():
    s = input().upper()

    size = ord('Z')-ord('A')+1
    check = [False]*size
    for c in s:
        t = ord(c) - ord('A')
        if 0 <= t < size:
            check[t] = True
    return False in check

print('pangram' if pangram() else 'not pangram')
