#Program to check if Post-Correspondence Problem has a solution with given String pairs
#if there is solution with in 15 string concatenations, it returns 1
#else it returns 0

def compare(a, b):
    i = 0
    while(i<len(a) and i<len(b)):
        if a[i]!=b[i]:
            return False
        i += 1
    return True

def ifSolution(a, b, x, y, depth):
    x1 = ''
    for i in range(depth-1):
        x1 += '\t'
    n = len(a)
    flag = 0
    print(x1, x)
    print(x1, y)
    if x == y and depth!=0:
        return 1
    if depth > 15:
        print(x1, 'recursion maxed out')
        return 0
    for i in range(n):
        if compare(x+a[i], y+b[i]):
            flag += ifSolution(a, b, x+a[i], y+b[i], depth+1)
    if flag is 0:
        return 0
    return 1
                

def main():
    a = []
    b = []
    n = int(input('enter number of pairs:'))
    print('enter pairs:')
    for i in range(n):
        a.append(input())
        b.append(input())
    print(a)
    print(b)
    print(ifSolution(a, b, '', '', 0))

main()
