## Practice Question on Label & Entry Box

from tkinter import *       # All the function available in the tkinter library

root = Tk()     # Root window

lb1 = Label(root, text = "First Name") ## Create a label with name First Name
lb1.pack(side = LEFT) ## Display the widget at specific location ## Default=Top

ent1 = Entry(root)    ## Create a text box
ent1.pack(side = LEFT)

lbl2 = Label(root, text = "Middle Name") ##Create a label with name Middle Name
lbl2.pack(side = LEFT)


ent2 = Entry(root)  ## create a text box
ent2.pack(side = LEFT)

btn = Button(root, text = "Submit")
btn.pack(side = LEFT)

root.mainloop()  ###  to invoke all the inbuilt functions available in the root
