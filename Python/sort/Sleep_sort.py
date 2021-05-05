'''
  Sleep sort is a sorting algorithm used to sort non-negative integers. Sleep sort works by creating a separate thread for each item in the input which is to be
  sorted and then each thread sleeps for an amount of time which is proportional to the value of corresponding array element. Therefore, the thread which is having
  the least amount of sleep time wakes up first and the element gets printed and then the second least element and so on. The largest element wakes up after a long
  time and then the element gets printed at the last and thus the output obtained is a sorted array.     
'''
  
import threading
import time

lock = threading.Lock()

class SleepSortThread(threading.Thread):
    def __init__(self, val):
        self.val = val
        threading.Thread.__init__(self)

    def run(self):
        global lock
        # Thread is made to sleep in proportion to value
        time.sleep(self.val * 0.01)
        # Acquire lock
        lock.acquire()
        print(self.val, end = " ")
        # Release lock
        lock.release()

def SleepSort(list):
    thread_array = []

    # Intialize a thread corresponding to each element in list
    for i in list:
        thread = SleepSortThread(i)
        thread_array.append(thread)

    # Start all Threads
    for i in thread_array:
        i.start()

    # Wait for all threads to terminate
    for i in thread_array:
        i.join()


if __name__ == "__main__" :
    unsorted_array =[]
    number_of_elements = int(input("Enter the number of elements : "))
    print("Enter the elements: ")
    for i in range(number_of_elements):
        element = int(input())
        unsorted_array.append(element)

    print("The elements in sorted manner are: ")
    sorted_array = SleepSort(unsorted_array)

'''
Enter the number of elements : 7

Enter the elements: 
10
20
40
5
9
88
104

The elements in sorted manner are:
5 9 10 20 40 88 104


Time Complexity -
    1. Best case - O(NlogN + max(input))
    2. Average case - O(NlogN + max(input))
    3. Worst case - O(NlogN + max(input))
    where N = number of elements in the input array, and array = input array elements
    
Space Complexity - O(N)

'''
