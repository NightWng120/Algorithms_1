import time;
inversions = 0

def countInversions(array, length):
    global inversions
    for i in range(length):
        for j in range(i + 1, length):
            if array[i] > array[j]:
                inversions += 1

def mergeSort(array):
    global inversions

    if len(array) < 2:
        # print(f'Base case return: {array}')
        return array

    # countInversions(array, len(array))
    A = mergeSort(array[:int(len(array)/2)])
    B = mergeSort(array[int(len(array)/2):])
    i = 0;
    j = 0;

    # print(f'Current array: {array}')
    # print(f'A array: {A}')
    # print(f'B array: {B}')
    for k in range(len(array)):
        if not A:

            if array[k] > B[j]:
                inversions += 1
            array[k] = B[j]
            if j + 1 == len(B):
                B = []
            else:
                j += 1

        elif not B:

            if array[k] > A[i]:
                inversions += 1
            array[k] = A[i]
            if i + 1 == len(A):
                A = []
            else:
                i += 1

        elif A and A[i] < B[j]:

            if array[k] > A[i]:
                inversions += 1
            array[k] = A[i]
            if i + 1 == len(A):
                A = []
            else:
                i += 1

        elif B and B[j] < A[i]:

            inversions += 1
            array[k] = B[j]
            if j + 1 == len(B):
                B = []
            else:
                j += 1

        elif B[j] == A[i]:

            array[k] = B[j]
            if j + 1 == len(B):
                B = []
            else:
                j += 1

    # print(f'No early return for array {array}')
    return array

def bubbleSort(array):
    temp = 0
    i = len(array)
    while i:
        for j in range(len(array) - 1):
            if array[j] > array[j + 1]:
                temp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = temp
        i -= 1
    return array


with open('Output.txt', 'r') as f:
    nums = [int(item.replace('\n', '')) for item in f.readlines()]




nums.reverse()
start = time.time();
nums = mergeSort(nums)
# with open('Output.txt', 'w') as f:
#     for num in nums:
#         f.write(f"{num}\n")
# print(nums)
print(f'Merge sort executed in {time.time() - start} seconds')
print(f'Total inversions: {inversions}')

# start = time.time();
# bubbleSort(nums)
# print(f'Bubble sort executed in {time.time() - start} seconds')
