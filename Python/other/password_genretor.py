import string
import random
if __name__ == '__main__':
    # The lower case for password
    accsi_1 = string.ascii_lowercase

    # the upper case for password
    accsi_2 = string.ascii_uppercase

    # The numbers for password
    digit_1 = string.digits
    # The symbols for password
    symbol = string.punctuation        # you can use punctuation  function here for the symbols.

    password_len = int(input(("Entre lenght of the Password That You Want:")))
    if password_len < 4:  # Condtions for not printing password
        print("Make your password strong. please entre greater to 4")
    else:
        all = accsi_1 + accsi_2 + digit_1 + symbol
        temp = random.sample(all, password_len)
        password = "".join(temp)
        print("Your password is:")
        print(password)

'''
Sample input
Entre lenght of the Password That You Want: 10

sample output
WI%pP[,x53

'''

# time complexity o(n)
# space complexity o(1)
