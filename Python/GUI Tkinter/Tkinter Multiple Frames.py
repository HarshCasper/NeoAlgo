from tkinter import * # Import everything from Tkinter Library

root = Tk()     # Window

root.title("Frame Program")

topframe = Frame(root)
topframe.pack(side = TOP)

bottomframe = Frame(root).pack(side = BOTTOM)

redbtn = Button(topframe, text = "Red", fg = "Red", bg = "yellow").pack()
greenbtn = Button(topframe, text = "Green", fg = "green", bg = "yellow").pack()
redbtn = Button(topframe, text = "Blue", fg = "blue", bg = "yellow").pack()
blackbtn = Button(bottomframe, text = "Black", fg = "Black", bg = "yellow").pack(side = BOTTOM)

root.mainloop()

# Maximise the tkinter window output to see the Full Output