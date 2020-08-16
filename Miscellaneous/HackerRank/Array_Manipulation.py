# Complete the arrayManipulation function below.
def arrayManipulation(n, queries):
    arr = [0]*n
    for value in queries:
        arr[value[0] - 1] += value[2]
        if value[1] != len(arr):
            arr[value[1]] -= value[2]
    maxval = 0
    val = 0
    print(arr)
    for q in arr:
        val += q
        if val > maxval:
            maxval = val
    return maxval
