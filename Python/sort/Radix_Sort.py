def radix_sort(arr):
    max_number = max(arr) #finding the number with the maximum number of digits
    arr_copy = arr[:] #making a copy of the original list
    
    for digit in range(len(str(max_number))): #iterating over the length of the number with the maximum digits
        place = digit + 1 #denotes the place value we are currently sorting according to; we do a +1 because the indices start from 0 but the place values start from 1
        digits = [[] for _ in range(10)] #initializing buckets for each base, i.e 10 (0 to 9) in this case
        for number in arr_copy: #iterating over the list that contains the unsorted list
            try: #this handles the case when the numbers with less digits than the maximum one is out of digits to be placed in a corresponding bucket
                digits[int(str(number)[-place])].append(number) #adding values to the corresponding buckets
            except IndexError: #handles the case when some smaller number(compared to the one with the maximum digits) is out of digits and places in it the 0 bucket
                digits[0].append(number) #adding the numbers to the 0 bucket
        arr_copy = [] #intializing an the empty array after placing all numbers into respective buckets for a single digit(LSD to MSD)
        for base in digits: #iterating over the buckets to collect back the numbers from the buckets
            arr_copy.extend(base) #collecting back the numbers from their respective buckets in a sorted manner as per a particular digit     
    return arr_copy #returning the sorted list
 
def main():
    unsorted_list = list(map(int, input("Enter space separated numbers for the list\n").split()))
    print("Unsorted List:", unsorted_list)
    print("Sorted List:", radix_sort(unsorted_list))
main() 
