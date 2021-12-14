## Write a program to create a registration form consisting of radio and check
# button into it.

from tkinter import * # Import everything from Tkinter Library

root = Tk()     # Window

def select():
    selection = "you have select the following option"+ var.get()
    lbl.config(text = selection)


var = StringVar()

rb1 = Radiobutton(root, text = "Male", variable = var, value = "Male", command = select)
rb1.pack()

rb2 = Radiobutton(root, text = "Female", variable = var, value = "Female", command = select)
rb2.pack()

rb3 = Radiobutton(root, text = "Transgender", variable = var, value = "Female", command = select)
rb3.pack()

rb4 = Radiobutton(root, text = "Prefer not to say", variable = var, value = "Prefer not to say", command = select)
rb4.pack()

var1 = StringVar()
var2 = StringVar()

ch1 = Checkbutton(root, text = "I agree that all the value selected are true to my knowledge", variable = var1, onvalue = 1, offvalue = 0, command = select) ## radio1
ch1.pack()

ch2 = Checkbutton(root, text = "I agree to all the Terms & Conditions", variable = var2, onvalue = 1, offvalue = 0, command = select)
ch2.pack()

btn = Button(text = "Submit", fg = "Red", bg = "yellow").pack()


lbl = Label(root)
lbl.pack()


root.mainloop()
