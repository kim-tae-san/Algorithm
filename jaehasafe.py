def getPartialMatch(s):
    begin = 1
    length = 0
    n = len(s)
    pm = [0] * n
    while n > begin:
        if s[begin] == s[length]:
            length += 1
            pm[begin] = length
            begin += 1
        else:
            if length == 0:
                begin += 1
            else:
                begin += length - pm[length - 1]
                length = pm[length - 1]
    return pm


def shifts(original, target):
    return kmpsearch(original * 2, target)

    
def kmpsearch(s, obj):
    pm = getPartialMatch(obj)
    n = len(s)
    m = len(obj)
    begin = 0
    matched = 0
    while n - m > begin:
        if matched < m and s[begin + matched] == obj[matched]:
            matched += 1
            if matched == m:
                return begin
        else:
            if matched == 0:
                begin += 1
            else:
                begin += matched - pm[matched - 1]
                length = pm[matched - 1]
    return begin
    
if __name__ == "__main__":
    C = int(input())
    for i in range(C):
        ret = 0
        N = int(input())
        current = input()
        states = []
        for j in range(N):
            states.append(input())
        cnt = 0
        for st in states:
            if cnt % 2 == 0:
                ret += shifts(st, current)
            else:
                ret += shifts(current, st)
            current = st
            cnt += 1
        print(ret)