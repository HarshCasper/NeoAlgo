def removeOuterParentheses(S):
        temp, result = "", ""
        start_bracket = 0
        for char in S:
            temp += char
            if char == '(':
                start_bracket += 1
            else:
                start_bracket -= 1
            if start_bracket == 0:
                result += temp[1:-1]
                temp = ""
        return result

str = "(()())(())"
result = removeOuterParentheses(str)
print(result)