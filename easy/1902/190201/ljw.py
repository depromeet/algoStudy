for _ in range(int(input())):
    s = input()
    a, b = 0, len(s)-1
    if a == b:
        print(-1)
    else:

      result = -1
      while a != b:
          if a == len(s)-1 or b == 0:
              break
          if s[a] == s[b]:
              a, b = a+1 , b-1
          else:
              if s[a] == s[b-1] and s[a+1] == s[b-2]:
                  result = b
                  break
              elif s[a+1] == s[b]:
                  result = a
                  break
              else:
                  result = a
                  br/eak
      print(result)
