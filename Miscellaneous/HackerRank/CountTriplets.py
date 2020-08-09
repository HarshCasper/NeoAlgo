from collections import defaultdict
def countTriplets(arr, r):
    v2 = defaultdict(int)
    print(v2)
    v3 = defaultdict(int)
    print(v3)
    count = 0
    for k in arr:
        count += v3[k]
        v3[k*r] += v2[k]
        v2[k*r] += 1
    return count
