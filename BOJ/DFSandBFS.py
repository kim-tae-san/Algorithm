import copy
from queue import Queue

n, m, v = map(int, input().split())

visited = [False for i in range(n+1)]

dic = dict()

for i in range(m):
    x, y = map(int, input().split())
    if x not in dic:
        dic[x] = list()
    if y not in dic:
        dic[y] = list()
    dic[x].append(y)
    dic[y].append(x)

bfs_dict = copy.deepcopy(dic)
bfs_visited = copy.deepcopy(visited)

for i in dic:
    dic[i] = sorted(dic[i])

def dfs(start, dic, vi):
    for i in dic[start]:
        if vi[i]:
            continue
        print(i, end=" ")
        vi[i] = True
        dfs(i, dic, vi)

def bfs(start, dic, vi):
    q = Queue()
    q.put(start)
    while not q.empty():
        top = q.get()
        if not vi[top]:
            print(top, end=" ")
        vi[top] = True
        for i in dic[top]:
            if vi[i]:
                continue
            q.put(i)


temp_dict = copy.deepcopy(dic)
temp_visited = copy.deepcopy(visited)
print(v, end=" ")
temp_visited[v] = True
if v in temp_dict:
    dfs(v, temp_dict, temp_visited)
    temp_dict = copy.deepcopy(dic)
    temp_visited = copy.deepcopy(visited)
    print()
    bfs(v, temp_dict, temp_visited)
else:
    print()
    print(v)