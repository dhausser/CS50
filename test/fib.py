def fib(n):
    if n < 1:
        return 0
    prev = 0
    curr = 1
    for _ in range(n):
        temp = prev + curr
        prev = curr
        curr = temp
    return curr

def to_binary(n):
    digits = []
    while n > 0:
        digits.append('1' if int(n) & 1 else '0')
        n /= 2
    return ''.join(reversed(digits))

for i in range(10):
    print (bin(fib(i)))
    