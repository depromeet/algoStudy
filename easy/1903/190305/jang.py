input()
s = input()
k = int(input())

def parse(c):
    if 'A' <= c <= 'Z':
        return chr(ord('A') + (ord(c)+k - ord('A')) % 26)
    elif 'a' <= c <= 'z':
        return chr(ord('a') + (ord(c)+k - ord('a')) % 26)
    else:
        return c

print(''.join(map(parse, s)))