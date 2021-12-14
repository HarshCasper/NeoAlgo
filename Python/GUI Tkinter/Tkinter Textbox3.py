## Write a program to create a employee registration window using tkinter.

from tkinter import * # Import everything from Tkinter Library

root = Tk()     # Window

root.title("Welcome to Employee Registration")

lbl1 = Label(root, text = "Full Name") 
lbl1.pack(side = LEFT) 
ent1 = Entry(root) 
ent1.pack(side = LEFT)

lbl2 = Label(root, text = "Employee Number") 
lbl2.pack(side = LEFT)
ent2 = Entry(root) 
ent2.pack(side = LEFT)

lbl3 = Label(root, text = "Age") 
lbl3.pack(side = LEFT)
ent3 = Entry(root) 
ent3.pack(side = LEFT)

lbl4 = Label(root, text = "Mobile Number") 
lbl4.pack(side = LEFT)
ent4 = Entry(root) 
ent4.pack(side = LEFT)

lbl5 = Label(root, text = "OTP") 
lbl5.pack(side = LEFT)
ent5 = Entry(root) 
ent5.pack(side = LEFT)

btn = Button(root, text = "Submit")
btn.pack(side = LEFT)

root.mainloop()
