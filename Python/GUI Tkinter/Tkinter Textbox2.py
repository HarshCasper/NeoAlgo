## Write a program to create a registration form for student consisting of
# atleast 5 different attributes using tkinter.

from tkinter import * # Import everything from Tkinter Library

root = Tk()     # Window 

lbl1 = Label(root, text = "First Name")
lbl1.pack() 
ent1 = Entry(root) 
ent1.pack()

lbl2 = Label(root, text = "Middle Name")
lbl2.pack()
ent2 = Entry(root)
ent2.pack()

lbl3 = Label(root, text = "Last Name") 
lbl3.pack()
ent3 = Entry(root) 
ent3.pack()

lbl4 = Label(root, text = "Age") 
lbl4.pack()
ent4 = Entry(root) 
ent4.pack()

lbl5 = Label(root, text = "Phone Number") 
lbl5.pack()
ent5 = Entry(root) 
ent5.pack()

btn = Button(root, text = "Submit")
btn.pack(side = LEFT)

root.mainloop()
