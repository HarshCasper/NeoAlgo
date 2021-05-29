/* Write a Python program to count the number of articles in a given text. */

CODE:

s=input("ENTER TEXT HERE")
y=s.split()
a=0
an=0
the=0
for i in range(len(y)):
if (y[i]=="a" or y[i]=="A"):
a=a+1
if (y[i]=="an" or y[i]=="An"):
an=an+1
if (y[i]=="the" or y[i]=="The"):
the=the+1
print("a:",a)
print("an:",an)
print("the:",the)
print("Total Articles:",a+an+the)

---------------------------------------------------------------------------------------------
TIME COMPLEXITY: O(N) (Where N is length)
SPACE COMPLEXITY: O(N)
------------------------------------------------------------------------------------------
OUTPUT:

ENTER TEXT HERE A was the an I am a the she was this that the an a the
a: 3
an: 2
the: 4
Total Articles: 9
