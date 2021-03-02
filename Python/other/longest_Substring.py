def longest_substring_length(string):
    """Returns length of the longest substring without repetition of characters """
    dct = {}
    result = 0
    start = 0
    counter = 0
    for index, val in enumerate(string):
        if val not in dct:
            dct[val] = index
            counter += 1
        else:
            if dct[val] >= start:
                start = dct[val] + 1
                counter = index - dct[val] -1
            counter += 1
            dct[val] = index
        result = max(result, counter)
    return result

test_case = int(input('No. of test cases:'))
while test_case:
    print(longest_substring_length(input()))
    test_case -= 1
    
"""
Input format:
3                       #No. of Test cases
abccddabc
bb
pwwkew

Approach:
di -> dictionary is used to keep track of duplicates.
counter-> to keep count of distinct chars since last occurence of duplicate character.
start-> start pointer from where counter starts.
If the character has its duplicate in the dictionary, we check its last occurence,
if its greater than start, then the counter becomes currentIndex - lastOccurence. Start becomes lastOccurence + 1
        
Complexity: Time: O(n) n-> length of string
            Space: O(n)
contributed by @pradeep98
"""
