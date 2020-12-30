''' Stock Span Problem
Given a list of prices of a stock for N number of days, find stock span for each day.
'''

def calcSpan(price):
    # Create a stack and array to store ans
    day = len(price)
    stack = []
    span = [0 for i in range(0, day)]
    # Span value of first day is 1
    span[0] = 1
    stack.append(0)
    # Calculate span values for rest of the elements
    for i in range(1, day):
        #  checking if previous stock prize is less
        while (len(stack) > 0 and price[stack[-1]] <= price[i]):
            stack.pop()
        # updating the span value
        if len(stack) <= 0:
            span[i] = i + 1
        else:
            span[i] = i - stack[-1]
        # Push element to stack
        stack.append(i)

    print(span)


prices = list(map(int, input().strip().split()))
calcSpan(prices)

'''
sample Input:
10 30 20 50 20
sample output:
1 2 1 4 1

Time complexity: O(n)
space complexity:O(n)
'''

