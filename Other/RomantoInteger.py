def RomantoInteger(s):
    #enumerate Roman number in dict
    Roman = {'M':1000, 'D':500, 'C':100, 'L':50, 'X':10, 'V':5, 'I':1}
    number = 0
    for index in range(0, len(s) - 1):
        if Roman[s[index]] < Roman[s[index + 1]]:
            number -= Roman[s[index]]
        else:
            number += Roman[s[index]]

    #add the last Roman number in the string
    return number + Roman[s[-1]]

if __name__ == '__main__':
    print RomantoInteger("MCMX")
