import string
import random
if __name__ == '__main__':
    # The lower case for password
    accsi_1 = string.ascii_lowercase

    #the upper case for password
    accsi_2 = string.ascii_uppercase

    #The numbers for password
    digit_1 = string.digits
    # The symbols for password
    symbol = ('@,#,$,&,*')          # you can use punctuions function here for the symbols.

    password_len = int(input(("Entre Password That You Want")))
    if password_len == 0: # condtions for not printing password
        print("Make your password storng. please entre greater to 4")
    if password_len == 1:
        print("Make your password storng. please entre greater to 4")
    if password_len == 2:
        print("Make your password storng. please entre greater to 4")
    if password_len == 3:
        print("Make your password storng. please entre greater to 4")

    else:
        all = accsi_1 + accsi_2 + digit_1 + symbol
        temp = random.sample(all, password_len)
        password = "".join(temp)
        print("Your password is:")
        print(password)

# time complexity o(n)
# space compplexity o(1)
