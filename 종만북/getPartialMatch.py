"""
    
    KMP algorithm

    Input : pattern

    Output : suffix, preffix length array

    Calculates suffix preffix length in pattern


    
    8/16 coded by bmkim
    
"""
def getPartialMatch(word):
    pi = [0] * len(word)
    
    leng = 0
    begin = 1
    while begin < len(word):
        if word[begin] == word[leng]:
            leng += 1
            pi[begin] = leng
            begin += 1
        else:
            if leng != 0:
                leng = pi[leng-1]
            else:
                begin += 1
    return pi


if __name__ == "__main__":
    s = input()
    s += input()
    ret = []
    length = getPartialMatch(s)
    k = len(length)
    while k > 0:
        ret.append(k)
        k = length[k-1]
    n = len(ret) - 1
    while n >= 0:
        print(ret[n], end=" ")
        n -= 1