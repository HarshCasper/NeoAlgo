''' Below code is an implementation of binary search in a iterative manner in python3.
    A List is taken as input from the user, followed by the element the user wants to
    search in the array. The search function is called. If the element is present 
    in the array, then print the index of the element in the array.
   
    NOTE : For binary search to work, the input array must be SORTED '''

# This function searchs for the element and prints the output
def binarysearch(n,List):

   # We start search on the entire List 
   start = 0
   end = len(List)-1
   mid = 0

   #we check if the search is valid or not
   if(start<=end):
     
       while(True):
     
          #updating the mid element according to the part we search for
          mid = (start+end)//2

          if List[mid] > n:

              # if n is smaller we ignore the right part
              end = mid-1

          elif List[mid] < n:

              # if n is greater we ignore the left part
              start = mid+1

          else:

              print("The element is present at the index : "+str(mid))
              return  

   else:
      print("Element not found in the List!")
      return 

if __name__ == '__main__':

   # This is the element we need to search for
   n = int(input("Enter the number you need to search :"))
   
   print("Please enter the List in sorted manner !\n")

   ''' Here we take the list of elements spaced and split them and
       store them in a List''' 
   list_elements = input("Enter the elements of the list with space :")
   List = list_elements.split()
   
   # Converting the string list into int list
   for i in range(0, len(List)):
      List[i] = int(List[i])

   #calling the binary search function
   binarysearch(n,List) 

'''
   Sample I/O :
  
   Enter the number you need to search :3
   Please enter the List in sorted manner !

   Enter the elements of the list with space :1 2 3 4
   The element is present at the index : 2 
 '''

