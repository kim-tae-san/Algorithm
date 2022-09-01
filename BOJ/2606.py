def get_input():
    n = int(input())
    m = int(input())
    network = []
    visited = [False for i in range(m)]
    for i in range(0, n+1):
        network.append([])
    for i in range(m):
        x, y = map(int, input().split())
        network[x].append(y)
        network[y].append(x)
    return network, visited

def dfs(start):
    network, visited = get_input()
    stack = []
    stack.append(start)
    visited[start] = True
    while len(stack) > 0:
        top = stack[-1]; stack.pop()
        visited[top] = True
        for i in network[top]:
            if visited[i]:
                continue
            stack.append(i)

print(dfs(1))