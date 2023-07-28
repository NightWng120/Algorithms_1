import random

with open('data.txt', 'w') as f:
    random.seed()
    for i in range(100000):
        if i + 1 == 100000:
            f.write(str(random.randint(1,1000)))
            break

        f.write(str(random.randint(1,1000)) + ",")
