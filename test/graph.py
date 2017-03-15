#http://eddmann.com/posts/depth-first-search-and-breadth-first-search-in-python/

#Adjacency list: build by storing each node in a dictionary along with a set containing their adjacent nodes
graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E'])}
         
tree = {2: {7, 5},
        7: {3, 6},
        5: {9},
        3: set(),
        6: {5, 11},
        9: {4},
        10: set(),
        11: set(),
        4: set()}
         