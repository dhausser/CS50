from collections import deque

queue = deque(['Eric', 'John', 'Michael'])
queue.append('Terry')
queue.append('Graham')
print(queue)
queue.popleft()
queue.popleft()
print(queue)
queue.pop()
print(queue)

squares = list(map(lambda x: x**2, range(10)))
squares2 = [x**2 for x in range(10)]
print (squares)
print (squares2)