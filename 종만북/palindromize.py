"""
    
    KMP algorithm

    Input : string

    Output : Min Palindrome length

    Makes Palindrome by using KMP algorithm

    8/23 coded by bmkim
    
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

def palindromize(s):
    rev = s[::-1]
    gpm = getPartialMatch(rev)
    begin = 0
    matched = 0
    while begin < len(s):
        if matched < len(s) and s[begin+matched] == rev[matched]:
            matched += 1
            if begin + matched == len(s):
                return matched + begin * 2
        else:
            if matched == 0:
                begin += 1
            else:
                begin += matched - gpm[matched-1]
                matched = gpm[matched-1]
    return 0

if __name__ == "__main__":
    C = int(input())
    for i in range(C):
        s = input()
        print(palindromize(s))
