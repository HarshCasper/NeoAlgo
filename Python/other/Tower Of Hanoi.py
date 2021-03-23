"""
   Tower of Hanoi 
Problem:
Given three rods and disks
The objective of the puzzle is to move the 
entire stack of disks to another rod.
The following rules needs to be followed:
    *Only one disk can be moved at a time.
    *Each move consists of taking the upper disk from one of the stacks and placing it on top
      of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
    *No disk may be placed on top of a smaller disk.
    
Input:
n_disks : number of disks

Output:
result: stack of disks moved from one rod to
        another based on the rules
"""
#function for tower of hanoi
#we have three rods source , auxilary and target
#putting n_disk from source rod  to the target rod using auxiallary rod

def tower_of_hanoi(n_disks, source, auxiliary, target):
    
    #if only one disk is on the rod
    if(n_disks == 1):  
        print('Move disk 1 from rod {} to rod {}.'.format(source, target))  
        return  
     
    
    tower_of_hanoi(n_disks - 1, source, target, auxiliary)  
    print('Move disk {} from rod {} to rod {}.'.format(n_disks, source, target)) 
    
    tower_of_hanoi(n_disks - 1, auxiliary, source, target)  
  
  
    
# here source is A, auxiliary is B and target is C  
n_disks = int(input('Enter the number of disks: '))
tower_of_hanoi(n_disks, 'A', 'B', 'C') 


# Sample Input/Output

#Enter the number of disks: 3

#Move disk 1 from rod A to rod C.
#Move disk 2 from rod A to rod B.
#Move disk 1 from rod C to rod B.
#Move disk 3 from rod A to rod C.
#Move disk 1 from rod B to rod A.
#Move disk 2 from rod B to rod C.
#Move disk 1 from rod A to rod C.

# number of moves  2n - 1.
# Time Complexity  O(2^n)