from collections import namedtuple

Result = namedtuple("Result","maxSum leftBound rightBound upBound lowBound")

KadanesResult = namedtuple("KadanesResult","maxSum start end")


def kadanes(temp):
    max = 0
    maxStart = -1
    maxEnd = -1
    currentStart = 0
    maxSoFar = 0

    for i in range(0, len(temp)):
        maxSoFar += temp[i]

        if maxSoFar < 0:
            maxSoFar = 0
            currentStart = i + 1

        if maxSoFar > max:
            maxStart = currentStart
            maxEnd = i
            max = maxSoFar

    return KadanesResult(max, maxStart, maxEnd)


def max_sub_sub_rectangle(rectangle):

    rows = len(rectangle)
    cols = len(rectangle[0])

    result = Result(float("-inf"), -1, -1, -1, -1)

    for left in range(cols):
        temp = [0 for _ in range(rows)]
        for right in range(left, cols):
            for i in range(rows):
                temp[i] += rectangle[i][right]

            kadanes_result = kadanes(temp)
            if kadanes_result.maxSum > result.maxSum:
                result = Result(kadanes_result.maxSum, left, right, kadanes_result.start, kadanes_result.end)

    return result

if __name__ == '__main__':
    rectangle = [[2,  1, -3, -4,  5],
                 [0,  6,  3,  4,  1],
                 [2, -2, -1,  4, -5],
                 [-3,  3,  1,  0,  3]]

    result = max_sub_sub_rectangle(rectangle)
    assert 18 == result.maxSum
    print (result)