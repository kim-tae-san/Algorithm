"""""""""""""""""""""""""""""""""""""""""""""""""""
    
    Programmers Lv.2 가장큰수

    Input : list of int

    Output : biggest permutation

    Calculates biggest permutation using sort


    
    10/6 coded by bmkim
    
"""""""""""""""""""""""""""""""""""""""""""""""""""
def solution(numbers):
    numbers = list(map(str, numbers))
    numbers.sort(key = lambda x: x*3, reverse = True)
    return str(int("".join(numbers)))