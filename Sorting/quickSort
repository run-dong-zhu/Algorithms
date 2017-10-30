unsort_array = [5, 1, 27, 29, 4, 3, 47, 2, 8, 14]

def quicksort(array, low, high):
    if low < high:
        q = partition(array, low, high)
        quicksort(array, low, q - 1)
        quicksort(array, q + 1, high)

    return array


def partition(array, low, high):
    #choose a pivot compared with each element
    pivot = array[high]
    #create a wall to divide element
    wall = low - 1
    for index in range(low, high):
        #if array[index] < pivot, place it in the other side of the wall
        if array[index] <= pivot:
            wall += 1
            array[wall], array[index] = array[index], array[wall]

    #switch the first element at the right of the wall and pivot
    array[wall + 1], array[high] = array[high], array[wall + 1]
    return wall + 1


if __name__ == '__main__':
    print quicksort(unsort_array, 0, len(unsort_array) - 1)
