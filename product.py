def gradeschool(i, j):

    if len(str(i)) == 1 or len(str(j)) == 1:
        return int(i) * int(j)

    n = len(str(i))
    a = (i - i%(10**(n/2)))/(10**(n/2))
    b = (i%(10**(n/2)))

    c = (j - j%(10**(n/2)))/(10**(n/2))
    d = (j%(10**(n/2)))

    # print(f'a: {a}\nb: {b}\nc: {c}\nc: {d}')
    # if 1 in memo:
    #     print(f'a: {a}\nb: {b}\nc: {c}\nc: {d}')
    #     return 
    # memo[1] = ''
    return (10**n) * gradeschool(int(a),int(c)) + (10**(n/2)) * (gradeschool(int(a),int(d)) + gradeschool(int(b),int(c))) + gradeschool(int(b),int(d))


print(gradeschool(87457821,23423459))


