def removeOuterParentheses(S):
    res, opened = [], 0
    for c in S:
        if c == '(' and opened > 0:
            res.append(c)
        if c == ')' and opened > 1:
            res.append(c)
        opened += 1 if c == '(' else -1
    return "".join(res)

str = input("Enter string: ")
result = removeOuterParentheses(str)
print(result)


"""
Time complexity: O(n)
Space complexity: O(n)
Sample Input 1:
Enter string: (()())(())
Output: ()()()

Sample Input 2:
Enter string: ()()
Output: ""

"""
