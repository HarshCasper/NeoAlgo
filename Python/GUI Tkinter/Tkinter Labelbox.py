from tkinter import * # Import everything from Tkinter Library

root = Tk()     # Window

lb = Listbox(root)
lb.insert(1,"Python")
lb.insert(2,"Java")
lb.insert(3,"C++")
lb.insert(4,"C")
lb.insert(5,"HTML")

lb.pack()

root.mainloop()
