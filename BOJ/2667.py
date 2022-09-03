from queue import Queue

direction = [[1, 0], [0, 1], [-1, 0], [0, -1]]

def get_input():
    n = int(input())
    apart = []
    for i in range(n):
        temp = list(map(int, input()))
        apart.append(temp)
    return apart, n


def validation(x, y, max_size):
    return x >= 0 and x < max_size and y >= 0 and y < max_size


def bfs(apart, a, b):
    num = 1
    n = len(apart)
    q = Queue()
    q.put([a, b])
    apart[a][b] = 0
    while not q.empty():
        item = q.get()
        y, x = item[0], item[1]
        for dir in direction:
            next_y = y + dir[0] 
            next_x = x + dir[1]
            if validation(next_x, next_y, n) and apart[next_y][next_x]:
                q.put([next_y, next_x])
                apart[next_y][next_x] = 0
                num += 1
    return num

def solution():
    apart, n = get_input()
    result = []
    for i in range(n):
        for j in range(n):
            if apart[i][j]:
                result.append(bfs(apart, i, j))
    result.sort()
    print(len(result))
    for i in result:
        print(i)

solution()