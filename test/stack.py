from math import log10

a = [1, 2, 3, 4, 5]
print(a)
a[10:] = [6]
print(a)
print(a[-3:])
print(a)
print(a[1:-2])
a.append(216)
a.append(7 ** 3)
print(a)
b = [5, 4, 3, 9, 4, 5, 6, 4 ,8, 4, 9, 4, 6, 4, 3]
a.extend(b)
print(a)
a.insert(6, 99)
print(a)
a.pop()
print(a)
a.pop()
print(a)
a.pop()
print(a)
print(a.index(99, 6, 7))
while b.count(4):
    b.remove(4)
print(b)
b.reverse()
print(b)
x = 123456789
print(1 + int(log10(x)))
b.pop()
print(b)

