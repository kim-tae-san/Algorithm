def Solution():
    num = list(map(int, input()))
    rev = num[::-1]
    s = []
    for i in range(len(num)):
        combnum = num[i] + rev[i]
        if combnum >= 10 and i == 0:
            s.append(combnum // 10)
            s.append(combnum % 10)
        elif combnum >= 10:
            s[-1] += 1 
            s.append(combnum % 10)
        else:
            s.append(combnum)
    if s == s[::-1]:
        return 'yes'
    return 'no'
    

if __name__ == "__main__":
    c = int(input())
    for i in range(c):
        print(Solution())