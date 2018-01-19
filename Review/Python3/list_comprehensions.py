lists = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

dic = {'A':1, 'B':2, 'C':3, 'D':4}

for index, value in enumerate(lists):
    print index, ':', value

for k, v in dic.items():
    print k, ':', v

print([x * x for x in range(1, 10) if x % 2 == 0])

print(lists)

generator = (x * x for x in range(1, 10))

print next(generator)
print next(generator)
print next(generator)
print next(generator)
print next(generator)
print next(generator)
print next(generator)
print next(generator)
print next(generator)
