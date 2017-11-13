L = [1, 3, 6, 11, 23, 31, 47, 59, 73, 91]


def binary_search(L, l, r, num):
    # Base case
    if r >= l:
        mid = l + (r - l) / 2
        if num == L[mid]:
            return mid
        # num in the left half
        elif num < L[mid]:
            return binary_search(L, l, mid-1, num)
        # num in the right half
        else:
            return binary_search(L, mid, r, num)

    else:
        # num not in the list
        return -1

if __name__ == '__main__':
    print binary_search(L, 0, len(L)-1, 59)
