unsort_array = [5, 1, 4, 2, 8]

def bubbleSort(arr):
    key = 0
    #elements before key are sorted
    while key < len(arr):
        for index in range(key, len(arr) - 1):
            #if the first one greater than second in pairs, swap
            if arr[index] > arr[index + 1]:
                temp = arr[index + 1]
                arr[index + 1] = arr[index]
                arr[index] = temp

        key = key + 1;

    print arr


if __name__ == '__main__':
    bubbleSort(unsort_array)
