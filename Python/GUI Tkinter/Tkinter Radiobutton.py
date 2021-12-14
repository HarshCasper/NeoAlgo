from tkinter import * # Import everything from Tkinter Library

root = Tk()     # Window


def select():
    selection = "You have select the following option: "+ var.get()
    lbl.config(text = selection)


var = StringVar()

rb1 = Radiobutton(root, text = "Male", variable = var, value = "Male", command = select)  ##radio1
rb1.pack()

rb2 = Radiobutton(root, text = "Female", variable = var, value = "Female", command = select) ### name--> variable
rb2.pack()

lbl = Label(root) #Label for displaying the text
lbl.pack()

root.mainloop()
