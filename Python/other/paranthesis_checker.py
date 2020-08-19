def checkParanthesis(input_string):
    ''' 
        argument : string

        Function checks whether the Brackets Combinations Provided As Input 
        is Balanced or Not.
        
        usage : checkParanthesis(string)
        
    '''



    # hashmap maintaing the open and closed brackets
    occurence = {"(":0 , ")":0, "{":0 , "}":0 , "[":0 , "]" : 0 , "<":0 , ">":0}
    # occurence supports common,curly,square and angle bracket

    for bracket in input_string:
        occurence[bracket]+=1

    if occurence["("] == occurence[")"] and occurence["{"] == occurence["}"]:
        if occurence["["] == occurence["]"] and occurence["<"] == occurence[">"]:
            print("Balanced")
        else:
            print("Not Balanced")
    else:
        print("Not Balanced")


if __name__ == "__main__":
    inp = input("Enter the Brackets Combinations\n")
    checkParanthesis(inp)
    
