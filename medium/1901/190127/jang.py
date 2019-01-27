n = int(input())
arr = list(map(int, input().split()))
enum_arr = sorted(enumerate(arr, start=1), key=lambda t: t[1])

frm = []
to = []

for i in range(1, len(enum_arr)+1):
    if enum_arr[i-1][0] != i:
        frm.append(i)
        to.append(enum_arr[i-1][0])

cvted = list(range(frm[0], frm[-1]+1))

if len(cvted) % 2 == 1:
    cvted.pop(len(cvted)//2)

if len(frm) == 0:
    print("yes")
elif len(frm) == 2 and frm == to[::-1]:
    print("yes")
    print("swap", *frm)
elif frm == to[::-1] and frm == cvted:
    print("yes")
    print("reverse", frm[0], frm[-1])
else:
    print("no")




