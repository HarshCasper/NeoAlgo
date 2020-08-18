# Z ALgorithm Function
def Z__Algo(text, pattern):
    List = []
    substring = ""

    """ Iterating upto the index where the substring can occur """
    for i in range(0, len(text) - len(pattern)+1):

        """ Extracting the --substring of the same length as pattern-- from the text """
        substring = text[i:i + len(pattern)]

        """ Loop for comparing the substring and pattern """
        c = 0
        for j in range(0, len(pattern)):

            """ If the charecters of substring and pattern matches , increment c by 1 """
            if pattern[j] == substring[j]:
                c += 1

        """ If all the charecters of substring and pattern matches , add position to list """
        if c == len(pattern):
            List.append(i)

    """ Return the list that contains all the positions the substring is present at """
    return List


# Searching Process
text = input("Enter Text : ")
pattern = input("Enter pattern : ")
positions = Z__Algo(text, pattern)

"""If list not empty , print positions , else prompt -- pattern not found"""
if len(positions) != 0:

    """Calling Z__Algo to seacrh the substring positions"""
    for position in positions:
        print("The pattern is present at : " + str(position))

else:
    print("Pattern Not Found !!!")
