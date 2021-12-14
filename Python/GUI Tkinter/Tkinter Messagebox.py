## Write a program to create mutiple buttons with player names of ICC WT20.
#Display whether that player is batsmen,bowler or allrounder using a messagebox.

from tkinter import * # Import everything from Tkinter Library
from tkinter import messagebox

root = Tk()     # Window
root.title("ICC WTsquad Indian Players Team")

##Players names
# Virat Kohli (C)                                                                                                                                       
# Rohit Sharma (VC)                                                                                                                                           
# KL Rahul                                                                                                                                       
# Suryakumar Yadav                                                                                                                       
# Rishabh Pant (wk)                                                                                                                                                                                                                                                                    
# Hardik Pandya                                                                                                                                       
# Ravindra Jadeja                                                                                                                                           
# Rahul Chahar                                                                                                                                                                                                                                                                                                                                                                                      
# Varun Chakravarthy                                                                                                   
# Jasprit Bumrah                                                                                                                                                                                                                                    
# Mohd Shami

def msg1():
    messagebox.showinfo("Virat Kohli","Captain, Batsman")
btn1 = Button(root, text = "Virat Kohli",bd=20,bg="red",fg="yellow",command = msg1).pack()

def msg2():
    messagebox.showinfo("Rohit Sharma","Vice Captain, Batsman")
btn2 = Button(root, text = "Rohit Sharma",bd=20,bg="blue",fg="pink",command = msg2).pack()

def msg3():
    messagebox.showinfo("KL Rahul","Batsman")
btn3 = Button(root, text = "KL Rahul",bd=20,bg="red",fg="yellow",command = msg3).pack()

def msg4():
    messagebox.showinfo("Suryakumar Yadav","Batsman")
btn4 = Button(root, text = "Suryakumar Yadav",bd=20,bg="blue",fg="pink",command = msg4).pack()

def msg5():
    messagebox.showinfo("Rishabh Pant","Wicket Keeper, Batsman")
btn5 = Button(root, text = "Rishabh Pant",bd=20,bg="red",fg="yellow",command = msg5).pack()

def msg6():
    messagebox.showinfo("Hardik Pandya","All Rounder")
btn6 = Button(root, text = "Hardik Pandya",bd=20,bg="blue",fg="pink",command = msg6).pack()

def msg7():
    messagebox.showinfo("Ravindra Jadeja","All Rounder")
btn7 = Button(root, text = "Ravindra Jadeja",bd=20,bg="red",fg="yellow",command = msg7).pack()

def msg8():
    messagebox.showinfo("Rahul Chahar","Bowler")
btn8 = Button(root, text = "Rahul Chahar",bd=20,bg="blue",fg="pink",command = msg8).pack()

def msg9():
    messagebox.showinfo("Varun Chakravarthy","Bowler")
btn9 = Button(root, text = "Varun Chakravarthy",bd=20,bg="red",fg="yellow",command = msg9).pack()

def msg10():
    messagebox.showinfo("Jasprit Bumrah","Bowler")
btn10 = Button(root, text = "Jasprit Bumrah",bd=20,bg="blue",fg="pink",command = msg10).pack()

def msg11():
    messagebox.showinfo("Mohd. Shami","Bowler")
btn11 = Button(root, text = "Mohd. Shami",bd=20,bg="red",fg="yellow",command = msg11).pack()

root.mainloop()

# Maxime the tkinter window and Click on the buttons to see the desired output