## Write a program to display different shape names button using frame of
# tkinter.

from tkinter import * # Import everything from Tkinter Library

root = Tk()     # Window

root.title("Shape name buttons")

topframe = Frame(root).pack(side = TOP)
leftframe = Frame(root).pack(side = LEFT)
rightframe = Frame(root).pack(side = RIGHT)
bottomframe = Frame(root).pack(side = BOTTOM)

sqrbtn = Button(topframe, text = "Square", fg = "red", bg = "white").pack(side = TOP)
recbtn = Button(leftframe, text = "Rectangle", fg = "blue", bg = "black").pack(side = LEFT)
tribtn = Button(rightframe, text = "Triangle", fg = "green", bg = "white").pack(side = RIGHT)
crlbtn = Button(bottomframe, text = "Circle", fg = "yellow", bg = "black").pack(side = BOTTOM)

root.mainloop()

# Kindly Maximise the tkinter window to see the Full Output