def MainFunction(arr, size):
    for i in range(size):
        if (abs(arr[i]) - 1 < size and arr[abs(arr[i]) - 1] > 0):
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]
    for i in range(size):
        if (arr[i] > 0):
            return i + 1
    return size + 1

def findpositive(arr, size):
    j= 0
    for i in range(size):
        if (arr[i] <= 0):
            arr[i], arr[j] = arr[j], arr[i]
            j += 1
    return MainFunction(arr[j:], size - j)
arr = list(map(int, input().split(" ")))
print("the smallest missing number", findpositive(arr, len(arr)))
