def longestSubstringLength(string):
    di = {}
    result = 0
    start = 0
    counter = 0
    for index, val in enumerate(string):
        if val not in di:
            di[val] = index
            counter += 1
        else:
            if di[val] >= start:
                start = di[val] + 1
                counter = index - di[val] -1
            counter += 1
            di[val] = index
        result = max(result, counter)
    return result

testCase = int(input('No. of test cases:'))
while testCase:
    print(longestSubstringLength(input()))
    testCase -= 1
    
'''
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
'''
