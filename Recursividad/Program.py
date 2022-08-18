def sum(n):
    if(n == 1):
        return n
    else:
        return n+sum(n-1)

def factorial(n):
    if(n==0):
        return 1
    else:
        return n*factorial(n-1)

def mcd(n,m):
    x = 0
    if(n==0):
        return m
    if(m==0):
        return n
    n = n%m
    x = mcd(m,n)
    return x


print(mcd(40, 12))




