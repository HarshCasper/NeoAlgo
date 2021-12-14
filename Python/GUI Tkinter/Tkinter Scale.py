from tkinter import * # Import everything from Tkinter Library

root = Tk()     # Window


def select():
    sel = "You have selected the scale value as:" + str(var.get())
    lbl.config(text = sel)


var = DoubleVar()

sc = Scale(root, variable = var, from_ = 500, to_ = 1000)
sc.pack()



btn = Button(root, text = "Show", command = select)
btn.pack()


lbl = Label(root)
lbl.pack()

root.mainloop()
