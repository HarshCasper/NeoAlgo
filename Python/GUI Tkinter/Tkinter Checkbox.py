from tkinter import * # Import everything from Tkinter Library

root = Tk()     # Window


def select():
    selection = "You have selected the following option: "+ var.get() # msg+ radiobutton value
    lbl.config(text = selection) # dynamically configuring the label


var1 = StringVar()
var2 = StringVar()


ch1 = Checkbutton(root, text = "Male", variable = var1, onvalue = 1, offvalue = 0, command = select) ## radio1
ch1.pack()

ch2 = Checkbutton(root, text = "Female", variable = var2, onvalue = 1, offvalue = 0, command = select) ### name--> variable ## radio1
ch2.pack()

lbl = Label(root) #label for displaying the text
lbl.pack()

root.mainloop()
