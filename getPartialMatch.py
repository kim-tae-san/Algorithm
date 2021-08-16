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
                pi[begin] = 0
                begin += 1
    
    return pi


if __name__ == "__main__":
    test = getPartialMatch("aabaa")
    print(test)