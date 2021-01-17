import matplotlib.pyplot as plt
import math as mt
import random as rand

# X and Y axis co-ordinates
xx = []
yy = []

# Function to be ploted i.e the value of y
f = lambda x : 2*x*x+5*x+3

# Diffrent function to try from

#f = lambda x : x
#f = lambda x : pow(x,2)
#f = lambda x : pow(x,3)
#f = lambda x : pow(x,4)
#f = lambda x : abs(x)
#f = lambda x : mt.sin(x)
#f = lambda x : mt.cos(x)
#f = lambda x : mt.tan(x)
#f = lambda x : rand.randint(0,100)
#f = lambda x : mt.sqrt(x)
#f = lambda x: 1/x

'''

NOTE: While choosing the function, Do check whether the range of limit is within
    the domain of the function.

    For example:- f(x)=1/x
        Here 0 is not in the domain of the function, 
        Hence try to modify the for loop with one or more conditional statements
        accordingly.
        
'''
# Number of Y co-ordinates
limit = 50

# Calculation the X co-ordinated using the function declared above
for i in range(-limit, limit):
    # if i==0:
    # continue
    xx.append(i)
    yy.append(f(i))

# plotting the points
plt.plot(xx, yy, linewidth=1)
plt.grid(color='black', linestyle='-', linewidth=0.30)

# Labeling the x axis
plt.xlabel('x - axis')

# Labeling the y axis
plt.ylabel('y - axis')

# giving a title to my graph
plt.title('Graph for the function :')

# function to show the plot
plt.show()
