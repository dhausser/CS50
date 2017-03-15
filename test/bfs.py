#http://eddmann.com/posts/depth-first-search-and-breadth-first-search-in-python/
from graph import graph
from graph import tree

#Connected component
def bfs(graph, start):
    visited, queue = set(), [start]
    while queue:
        vertex = queue.pop(0)
        if vertex not in visited:
            visited.add(vertex)
            queue.extend(graph[vertex] - visited)
    return visited

#Paths
def bfs_path(graph, start, goal):
    queue = [(start, [start])]
    while queue:
        (vertex, path) = queue.pop(0)
        for next in graph[vertex] - set(path):
            if next == goal:
                yield path + [next]
            else:
                queue.append((next, path + [next]))

#Shortest Path
def shortest_path(graph, start, goal):
    try:
        return next(bfs_path(graph, start, goal))
    except StopIteration:
        return None

print('BFS connected component: {}'.format(bfs(graph, 'A')))
print('BFS paths: {}'.format(list(bfs_path(graph, 'A', 'F'))))
print(shortest_path(graph, 'A', 'F'))
print(shortest_path(tree, 2, 11))
print(shortest_path(tree, 2, 4))
print(shortest_path(tree, 2, 3))