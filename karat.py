def karatsuba(i, j):

    if len(str(i)) == 1 or len(str(j)) == 1:
        return int(i) * int(j)

    n = len(str(i))

    a = (i - i%(10**(n/2)))/(10**(n/2))
    b = (i%(10**(n/2)))

    c = (j - j%(10**(n/2)))/(10**(n/2))
    d = (j%(10**(n/2)))

    ac = karatsuba(int(a), int(c))
    bd = karatsuba(int(b), int(d))
    sum = karatsuba(int(a + b), int(c + d)) - ac - bd 

    return (10**n) * ac + (10**(n/2)) * (sum) + bd


print(karatsuba(1234,5678))


