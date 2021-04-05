def nextPermutation(array):
        """
        Function for next Permutation
        """
        length = len(array)
        if length <= 2:
            return array.reverse()
        pointer = length - 2
        
        while pointer >= 0 and array[pointer] >= array[pointer + 1]:
            pointer -= 1
        
        if pointer == -1:
            return array.reverse()
        
        for number in range(length - 1, pointer, -1):
            if array[pointer] < array[number]:
                array[pointer], array[number] = array[number], array[pointer]
                break
        
        array[pointer + 1:] = reversed(array[pointer + 1:])
        return array


def main():

    #User input for both the strings
    print('Enter values of the array')
    array = list(map(int, input().rstrip().split()))
    
    print(nextPermutation(array))

main()

"""
Input: numbers = [1,1,5]
Output: [1,5,1]
Input: numbers = [3,2,1]
Output: [1,2,3]
"""
