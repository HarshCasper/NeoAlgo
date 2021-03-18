print("GUESSING GAME")
guessed_num = []
secret_num = 54
for i in range(1, 101):
    x = int(input("Guess the secret number between 1 - 100 = "))
    if x < secret_num:
        print("Too low")
        guessed_num.append(x)
    elif x > secret_num:
        print("Too high")
        guessed_num.append(x)
    elif x == secret_num:
        print("You've found it!")
        guessed_num.append(x)
        break
for i in range(len(guessed_num)):
    guessed_num[i] = str(guessed_num[i])
r = ","
print("Your guessed numbers = ", r.join(guessed_num))
