#http://eddmann.com/posts/depth-first-search-and-breadth-first-search-in-python/
from graph import graph

#Connected Component
def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    for next in graph[start] - visited:
        dfs(graph, next, visited)
    return visited

#Paths
def dfs_paths(graph, start, goal, path=None):
    if path is None:
        path = [start]
    if start == goal:
        yield path
    for next in graph[start] - set(path):
        yield from dfs_paths(graph, next, goal, path + [next])

print(dfs(graph, 'A'))
print(list(dfs_paths(graph, 'A', 'F')))
