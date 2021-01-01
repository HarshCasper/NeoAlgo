'''
Author : @anushkrishnav
Problem : https://www.hackerrank.com/challenges/box-operations/problem
'''
import math
def Solution(op, box):
    if op[0] == 3:
            print(min(box[op[1]:op[2]+1]))
    elif op[0] == 4:
            print(sum(box[op[1]:op[2]+1]))
    elif op[0] == 1:
            box[op[1]:op[2]+1] = map(lambda x: x+op[3], box[op[1]:op[2]+1])
    elif op[0] == 2:
            box[op[1]:op[2]+1] = map(lambda x: math.floor(x/op[3]), box[op[1]:op[2]+1])



if __name__ == '__main__':
    nq = input().split()

    n = int(nq[0])

    q = int(nq[1])

    box = list(map(int, input().rstrip().split()))

    for i in range(q):
        op = list(map(int, input().split()))
        Solution(op, box)