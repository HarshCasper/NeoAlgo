#The Boyer–Moore majority vote algorithm is an algorithm for finding the majority of a sequence of elements using linear time and constant space.
def counting_fun(array):
    count_temp = 0                       # stores occurence count
    for i in range(0, len(array)):
        count_temp = array.count(array[i])   # Counts the occurence
        if count_temp > number/2:
            print(f"Number occuring more than n/2 is :{array[i]}")
            count_temp = "True"
            break
    if(count_temp != "True"):
        print("No Element occuring more than n/2")
number = int(input("Enter Number of values you will enter(eg.6): "))
i = 0
list_1 = []                         # List Declaration
print(f"Enter {number} values: ")
for i in range(0, number):
    elements = int(input())
    list_1.append(elements)         # adding element to the list

counting_fun(list_1)

# Output:
# Enter 6 values:
# 1
# 1
# 1
# 1
# 4
# 2
# Number occuring more than n/2 is: 1
# Time Complexity : o(n) , Space Complexity : o(1)
