from collections import defaultdict
import sys


def subArraylen(arr, n, K):
    mp = defaultdict(lambda: 0)
    mp[arr[0]] = 0
    for i in range(1, n):
        arr[i] = arr[i] + arr[i - 1]
        mp[arr[i]] = i
    ln = sys.maxsize
    for i in range(n):
        if(arr[i] < K):
            continue
        else:
            x = K - arr[i]
            if(x == 0):
                ln = min(ln, i)
            if(x in mp.keys()):
                continue
            else:
                ln = min(ln,  i - mp[x])
    return ln
arr = []
n = int(input("enter the number of elements"))
for i in range(0, n):
    ele = int(input("enter the elements"))
    arr.append(ele)
K = int(input("enter the sum "))
ln = subArraylen(arr, n, K)
if(ln == sys.maxsize):
    print("-1")
else:
    print(ln)

# Time complexity: O(NlogN)
# Space Complexity: O(N)
'''
Output:
enter the number of elements6
enter the elements2
enter the elements4
enter the elements6
enter the elements10
enter the elements2
enter the elements1
enter the sum 12
2
'''
