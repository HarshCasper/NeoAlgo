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
    # move one disc from source to target      
    tower_of_hanoi(n_disks - 1, source, target, auxiliary)  
    print('Move disk {} from rod {} to rod {}.'.format(n_disks, source, target)) 
    
    # move `N-1` discs from auxiliary to target using 
    #the source as an intermediate pole
    tower_of_hanoi(n_disks - 1, auxiliary, source, target)  
  
  
if __name__ == "__main__":
    # here source is X, auxiliary is Y and target is Z  
    n_disks = int(input('Enter the number of disks: '))
    tower_of_hanoi(n_disks, 'X', 'Y', 'Z') 

""" 
Sample Input/Output

Enter the number of disks: 3

Move disk 1 from rod X to rod Z.
Move disk 2 from rod X to rod Y.
Move disk 1 from rod Z to rod Y.
Move disk 3 from rod X to rod Z.
Move disk 1 from rod Y to rod X.
Move disk 2 from rod Y to rod Z.
Move disk 1 from rod X to rod Z.

number of moves  2n - 1.
Time Complexity  O(2^n)  
"""
