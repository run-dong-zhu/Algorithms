from decimal import Decimal

stock = [13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7]

def max_subarray(arr, l, r):
    mid = len(arr) / 2
    # Max left-sum
    left_sum = Decimal('-Infinity')
    max_sum = 0
    max_left = 0
    for index in range(mid, l, -1):
        max_sum += arr[index]
        if max_sum > left_sum:
            left_sum = max_sum
            max_left = index
    # Max right-sum
    max_right = 0
    right_sum = Decimal('-Infinity')
    for index in range(mid+1, r):
        max_sum += arr[index]
        if max_sum > right_sum:
            right_sum = max_sum
            max_right = index

    return (max_left, max_right)

if __name__ == '__main__':
    print max_subarray(stock, 0, len(stock)-1)
