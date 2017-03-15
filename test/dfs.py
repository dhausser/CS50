#http://eddmann.com/posts/depth-first-search-and-breadth-first-search-in-python/
from graph import graph
from graph import tree

#Connected Component
def dfs(graph, start):
    visited, stack = set(), [start]
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            stack.extend(graph[vertex] - visited)
    return visited
    
#Paths
def dfs_paths(graph, start, goal):
    stack = [(start, [start])]
    while stack:
        (vertex, path) = stack.pop()
        for next in graph[vertex] - set(path):
            if next == goal:
                yield path + [next]
            else:
                stack.append((next, path + [next]))

#print(dfs(graph, 'A'))
print('DFS connected components: {}'.format(list(dfs_paths(graph, 'A', 'F'))))
print('DFS paths: {}'.format(list(dfs_paths(graph, 'A', 'F'))))