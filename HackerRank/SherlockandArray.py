def balancedSums(arr):
    leftsum = 0
    total = sum(arr)
    for value in arr:
        if leftsum == total-value-leftsum:
            return "YES"
        leftsum+=value
    return "NO"