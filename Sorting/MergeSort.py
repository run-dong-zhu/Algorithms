unsort_array = [5, 1, 4, 2, 8]

def mergeSort(arr):
    #Base case
    if len(arr) <= 1:
        return arr

    #Recursive case. First, divide the list into equal-sized sublists
    #consisting of the first half and second half of the list.
    mid = int(len(arr) / 2)
    left = mergeSort(arr[:mid])
    right = mergeSort(arr[mid:])

    #Then merge the now-sorted sublists
    return merge(left, right)


def merge(left, right):
    l = 0
    r = 0
    result = []

    while l < len(left) and r < len(right):
        if left[l] <= right[r]:
            result.append(left[l])
            l = l + 1
        else:
            result.append(right[r])
            r += 1

    #Either left or right may have elements left; consume them
    result += left[l:]
    result += right[r:]

    return result


if __name__ == '__main__':
    print mergeSort(unsort_array)
