"""""""""""""""""""""""""""""""""""""""""""""""""""
    
    제 6회 한기대 프로그래밍 대회 A번 문제

    Input : two string

    Output : Longest dividable String

    Find the Longest dividable string


    
    9/27 coded by bmkim
    
"""""""""""""""""""""""""""""""""""""""""""""""""""
def solution(a, b):
    comp, obj = a, b
    if len(a) > len(b):
        comp, obj = b, a
    n = 1
    slc = len(comp) // n 
    while slc > 0:
        if len(comp) % n != 0:
            n += 1
            slc = len(comp) // n
            continue
        if comp[:slc] * n == comp:
            i = 1
            while i * slc <= len(obj):
                if comp[:slc] * i == obj:
                    return comp[:slc]
                i += 1
        n += 1
        slc = len(comp) // n
    return ""


c = int(input())
for i in range(c):
    a, b = input().split()
    print(solution(a, b))