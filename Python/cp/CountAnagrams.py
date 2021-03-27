'''
Given two strings <target> and <text>, write a program to find the number
of anagrams of <target> that can be found in the string <text>
Length of the <target> <= length of <text> <= 10^5
'''

from collections import Counter


def countAnagrams(target, text):

    '''
    This function returns the number of anagrams of string <target> which are
    present in the string <text>

    Parameters:
    target: string whose anagrams need to be counted
    text: string where the anagrams need to be counted

    '''

    k = len(target)
    n = len(text)
    # initialize a hashmap/ dictionary which stores the key value pairs
    # for frequencies of all the characters of the target string
    required = Counter(target)
    # similarly initialize the window with the first k characters
    # of the string <text>

    window = Counter(text[:k])
    # this variable will contain the number of anagrams
    answer = 0
    for i in range(n-k):
        # checking if all the characters of the current window are matching
        # with the characters of the target
        if window & required == required:
            answer += 1
        # decrementing the frequency of the character outside the window
        # incrementing the frequency of the character entering the window
        window[text[i]] -= 1
        window[text[i+k]] += 1
    # computing the answer for the last window
    if window & required == required:
        answer += 1
    return answer


# Driver Code
if __name__ == "__main__":

    s1 = input('Enter the target string : ')
    s2 = input('Enter the text string : ')

    print('The number of anagrams of "{}" in "{}" are: '.format(s1, s2))
    print(countAnagrams(s1, s2))

problemDetails = '''
Time Complexity:
O(n) where n is the length of the string <text>
additional time complexity : O(k) where k is length of the target string
since n > k : overall time complexity of the code => O(n)

Space complexity:
O(1) is the overall space complexity of this code, since the length of the
window cannot excede 26 ( alphabet)

Test cases:
TC-1
Input:
Enter the target string : abc
Enter the text string : bcabxabc
Output:
The number of anagrams of "abc" in "bcabxabc" are:  3

TC-2
Input:
Enter the target string : algo
Enter the text string : neoalgoneoprogalgoolagneoprogalog
Output"
The number of anagrams of "algo" in "neoalgoneoprogalgoolagneoprogalog" are:  8
'''
