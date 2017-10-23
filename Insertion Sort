unsort_array = [5, 4, 2, 1, 3]

def insertionSort(arr):
    for index in range(1, len(arr)):
        # choose a key as a card you want to insert
        key = arr[index]
        # insert arr[index] into the sorted sequence arr[0...i]
        i = index - 1
        while (i > -1 and arr[i] > key):
            arr[i + 1] = arr[i]
            i = i - 1

        arr[i + 1] = key

    print arr


if __name__ == '__main__':
    insertionSort(unsort_array)
