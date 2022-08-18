##function that returns a list of prime numbers
##between two numbers
def primes(a,b):
    lst = []
    for i in range(a,b):
        if i > 1:
            for j in range(2,i):
                if (i % j) == 0:
                    break
            else:
                lst.append(i)
    return lst

print(primes(1,100))