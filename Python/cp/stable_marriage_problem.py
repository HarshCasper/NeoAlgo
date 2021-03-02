import numpy as np


def wPrefersM1OverM(prefer, w, m, m1):
    for i in range(N):
        if (prefer[w][i] == m1):
            return True
        if (prefer[w][i] == m):
            return False


def stableMarriage(prefer):
    wPartner = [-1 for i in range(N)]
    mFree = [False for i in range(N)]

    freeCount = N
    while (freeCount > 0):
        m = 0
        while (m < N):
            if mFree[m] == False:
                break
            m += 1
        i = 0
        while i < N and mFree[m] == False:
            w = prefer[m][i]
            if (wPartner[w - N] == -1):
                wPartner[w - N] = m
                mFree[m] = True
                freeCount -= 1

            else:
                m1 = wPartner[w - N]
                if (wPrefersM1OverM(prefer, w, m, m1) == False):
                    wPartner[w - N] = m
                    mFree[m] = True
                    mFree[m1] = False
            i += 1
    print("Woman ", " Man")
    for i in range(N):
        print(i + N, "\t", wPartner[i])

N = int(input("Enter the number of men/women: "))
print("Enter preferences:")
entries = list(map(int, input().split()))
prefer = np.array(entries).reshape(2*N, N)
stableMarriage(prefer)

"""
Time Complexity:O(n2)
Sample Input:
Enter the number of men/women: 4
Enter preferences: 7 5 6 4 5 4 6 7 4 5 6 7 4 5 6
                   7 0 1 2 3 0 1 2 3 0 1 2 3 0 1 2 3
Output:
Woman  Man
4     2
5 	 1
6 	 3
7 	 0
"""
