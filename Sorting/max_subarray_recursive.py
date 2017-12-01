from decimal import Decimal

# stock = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
stock = [1, -4, 3, 2]

def max_crossing_subarray(arr, l, m, r):
    #mid = len(arr) / 2
    # Max left-sum
    left_sum = Decimal('-Infinity')
    max_sum = 0
    max_left = 0
    for index in range(m, 0, -1):
        max_sum += arr[index]
        if max_sum > left_sum:
            left_sum = max_sum
            max_left = index

    # Max right-sum
    right_sum = Decimal('-Infinity')
    max_sum = 0
    max_right = 0
    for index in range(m+1, r):
        max_sum += arr[index]
        if max_sum > right_sum:
            right_sum = max_sum
            max_right = index

    return max_left, max_right, left_sum + right_sum


def max_subarray_recurrsive(arr, l, r):
    if l >= r:
        return(l, r, arr[l])
    else:
        mid = (l + r) / 2
        leftlow, lefthigh, left_sum= max_subarray_recurrsive(arr, l, mid)
        #left_sum = sum(arr[i] for i in range(leftlow, lefthigh))

        rightlow, righthigh, right_sum = max_subarray_recurrsive(arr, mid+1, r)
        #right_sum = sum(arr[i] for i in range(rightlow, righthigh))

        crosslow, crosshigh, cross_sum = max_crossing_subarray(arr, l, (l+r)/2, r+1)
        #cross_sum = sum(arr[i] for i in range(crosslow, crosshigh))

        if left_sum > right_sum and left_sum > cross_sum:
            return(leftlow, lefthigh, left_sum)
        elif right_sum > left_sum and right_sum > cross_sum:
            return(rightlow, righthigh, right_sum)
        else:
            return(crosslow, crosshigh, cross_sum)


if __name__ == '__main__':
    #print max_crossing_subarray(stock, 0, len(stock)-1)
    print max_subarray_recurrsive(stock, 0, len(stock)-1)
