## This Program Checks the maximum occurence of a number in a array/list
def counting_fun(array):
    count_temp = 0                       #For storing the occurence of a number
    for i in range(0,len(array)):
        count_temp = array.count(array[i])   # Counts the occurence 
        if count_temp > number/2:
            print(f"Number occuring more than n/2 is :{array[i]}")  ##Prints the number with max occurence
            count_temp = "True"
            break
    if(count_temp != "True"):       
        print("No Element occuring more than n/2")

  #Read Program from Here ->  
number = int(input("Enter Number of values you will enter(eg. 6) : ")) 
i=0
list_1 = []                         # List Declaration
print(f"Enter {number} values: ")
for i in range(0, number): 
    elements = int(input()) 
    list_1.append(elements)         # adding element to the list
      
counting_fun(list_1)
  
  #Go to the line 1 for reading function


  ## Output :

/* Enter 6 values: 
1
1
1
1
4
2
Number occuring more than n/2 is :1  */

