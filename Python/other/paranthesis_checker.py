def checkParanthesis(s):
    # hashmap maintaing the open and closed brackets
    occurence = {"(":0 , ")":0, "{":0 , "}":0 , "[":0 , "]" : 0 , "<":0 , ">":0}
    # occurence supports common,curly,square and angle bracket

    for i in s:
        occurence[i]+=1

    if occurence["("] == occurence[")"] and occurence["{"] == occurence["}"]:
        if occurence["["] == occurence["]"] and occurence["<"] == occurence[">"]:
            print("Yes")
        else:
            print("No")
    else:
        print("No")


if __name__ == "__main__":
    inp = input()
    checkParanthesis(inp)
