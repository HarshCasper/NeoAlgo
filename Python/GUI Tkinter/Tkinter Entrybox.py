from tkinter import * # Import everything from Tkinter Library

root = Tk()     # Window

lbl = Label(root, text = "User Name").pack()
lbl = Label(root, text = "Password").pack()
ent1 = Entry(root).pack()
ent2 = Entry(root).pack()

root.mainloop()