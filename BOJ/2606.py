def get_input():
    n = int(input())
    m = int(input())
    network = []
    visited = [False for i in range(n+1)]
    for i in range(n+1):
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
    cnt = 0
    if len(network[start]) == 0:
        return cnt
    while len(stack) > 0:
        top = stack[-1]; stack.pop()
        if not visited[top]:
            cnt += 1
        visited[top] = True
        for i in network[top]:
            if visited[i]:
                continue
            stack.append(i)
    return cnt

cnt = 0
network, visited = get_input()
def dfs2(start):
    global cnt
    for i in network[start]:
        if not visited[i]:
            visited[i] = True
            cnt+=1
            dfs2(i)

visited[1] = True
dfs2(1)
print(cnt)