from queue import Queue

move = [
    [1, 1], [1, 0], [1, -1], [0, 1], [0, 0], [0, -1], [-1, 1], [-1, 0], [-1, -1]
]

def get_input():
    n, m = map(int, input().split())
    visited = []
    maze = []
    for i in range(n):
        maze.append(list(map(int, input())))
        visited.append([False for x in range(m)])
    return maze, visited, [n-1, m-1]

def validation(x, y, x_max, y_max):
    return x >= 0 and x < x_max and y >= 0 and y < y_max

def bfs(start):
    maze, visited, finish = get_input()
    q = Queue()
    q.put(start)
    while not q.empty():
        current = q.get()
        y, x = current[0], current[1]
        if visited[y][x]:
            continue
        visited[y][x] = True
        print(current)
        if current[:2] == finish:
            return current[2]
        else:
            for direction in move:
                x_plus, y_plus = direction[0], direction[1]
                next_x, next_y = x + x_plus, y + y_plus
                if validation(next_x, next_y, len(maze[0]), len(maze)) and maze[next_y][next_x]:
                    q.put([next_y, next_x, current[2] + 1]) 
    
print(bfs([0, 0, 1]))