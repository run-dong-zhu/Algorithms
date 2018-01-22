'''
In mathematics and computer science, a higher-order function 
(also functional, functional form or functor) is a function that does at least one of the following:
1. takes one or more functions as arguments (i.e., procedural parameters),
2. returns a function as its result.
'''
def add(x, y, f):
    return f(x) + f(y)


# map()
def f_cubic(x):
    return x * x * x


def normalize(name):
    return name[0].upper() + name[1:].lower()


# reduce()
DIGITS = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

def str2int(s):
    def f_mul(x, y):
        return x * 10 + y

    def char2int(s):
        return DIGITS[s]

    return reduce(f_mul, map(char2int, s))


def prod(l):
    def mul(x, y):
        return x * y

    return reduce(mul, l)


# filter()
def is_palindrome(n):
    if str(n) == str(n)[::-1] :
        return True
    

def main():
    print add(5, -5, abs)
    print list(map(normalize, ['adam', 'LISA', 'barT']))
    print list(map(f_cubic, [1, 2, 3, 4, 5]))
    print str2int('13579')
    print prod([3, 7, 5, 9])
    print list(filter(is_palindrome, range(0, 1000)))

if __name__ == "__main__":
    main()
