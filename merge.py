import time;
def mergeSort(array):
    if len(array) < 2:
        # print(f'Base case return: {array}')
        return array

    A = mergeSort(array[:int(len(array)/2)])
    B = mergeSort(array[int(len(array)/2):])
    i = 0;
    j = 0;

    # print(f'Current array: {array}')
    # print(f'A array: {A}')
    # print(f'B array: {B}')
    for k in range(len(array)):
        if not A:
            array[k] = B[j]
            if j + 1 == len(B):
                B = []
            else:
                j += 1


        elif not B:
            array[k] = A[i]
            if i + 1 == len(A):
                A = []
            else:
                i += 1

        elif A and A[i] < B[j]:
            array[k] = A[i]
            if i + 1 == len(A):
                A = []
            else:
                i += 1

        elif B and B[j] < A[i]:
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


with open('data.txt', 'r') as f:
    nums = list(map(int, f.readlines()[0].split(',')))



start = time.time();
print(mergeSort(nums))
print(type(nums[0]))
print(f'Merge sort executed in {time.time() - start} seconds')

# start = time.time();
# bubbleSort(nums)
# print(f'Bubble sort executed in {time.time() - start} seconds')
