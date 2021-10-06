"""""""""""""""""""""""""""""""""""""""""""""""""""
    
    Programmers Lv.1 K번째 수

    Input : command vector

    Output : result number

    Implement commands


    
    10/6 coded by bmkim
    
"""""""""""""""""""""""""""""""""""""""""""""""""""
def solution(array, commands):
    answer = []
    for com in commands:
        ret = array[com[0]-1:com[1]]
        ret.sort()
        answer.append(ret[com[2]-1])
    return answer