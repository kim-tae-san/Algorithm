c = int(input())
for i in range(c):
    num = int(input())
    print(format((num // 1000000) % 100, '02'))