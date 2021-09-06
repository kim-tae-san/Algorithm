def Solution():
    num = input()
    rev = num[::-1]
    num = int(num) + int(rev)
    num = list(map(int, str(num)))
    if num == num[::-1]:
        return 'yes'
    return 'no'
    

if __name__ == "__main__":
    c = int(input())
    for i in range(c):
        print(Solution())