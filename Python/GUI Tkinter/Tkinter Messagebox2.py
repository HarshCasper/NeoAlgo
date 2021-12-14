## Write a program to create a button reflecting various shape of geometry.
# After clicking on the button its area calculation formula should be reflected.

from tkinter import * # Import everything from Tkinter Library 
from tkinter import messagebox

root = Tk()     # Window
root.title("Various Geometry Shapes")

##Shapes
# Triangle                                                                                                                                       
# Square                                                                                                                                           
# Rectangle                                                                                                                                       
# Circle

def msg1():
    messagebox.showinfo("Triangle","Area = 0.5 * Base * Height")
btn1 = Button(root, text = "Triangle",bd=25,bg="red",fg="yellow",command = msg1).pack()

def msg2():
    messagebox.showinfo("Square","Area = Side * Side")
btn2 = Button(root, text = "Square",bd=21,bg="blue",fg="pink",command = msg2).pack()

def msg3():
    messagebox.showinfo("Rectangle","Area = Length * Breadth")
btn3 = Button(root, text = "Rectangle",bd=25,bg="red",fg="yellow",command = msg3).pack()

def msg4():
    messagebox.showinfo("Circle","Area = 3.14 * radius * radius")
btn4 = Button(root, text = "Circle",bd=21,bg="blue",fg="pink",command = msg4).pack()

root.mainloop()

# Maxime the tkinter window and Click on the buttons to see the desired output