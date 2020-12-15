"""
Edit Distance using dp
m: length of first string
n: length of second string
Time Complexity : O(m*n) (Looping through both strings)
Space Complexity : O(m*n) (Matrix distance)
"""


def editDist(firstString, secondString):
  # Length of both strings
  firstLength = len(firstString)
  secondLength = len(secondString)

  # Distance table for computing editDistance
  # Initializing edit distances as 0
  distance = [[0 for x in range(secondLength + 1)]
              for x in range(firstLength + 1)]

  # Looping and comparing each letter of firstString with each of secondString
  for firstSubString in range(firstLength + 1):
    for secondSubString in range(secondLength + 1):

      if firstSubString == 0:
        # firstSubString is empty, so insert all charecters of secondSubString
        distance[firstSubString][secondSubString] = secondSubString

      elif secondSubString == 0:
        # secondSubString is empty, so insert all charecters of firstSubString
        distance[firstSubString][secondSubString] = firstSubString

      elif firstString[firstSubString - 1] == secondString[secondSubString - 1]:
        # If last charecters of both substring are same, no operation required here
        # It's value will be equal to the editDistance of the substring without this same charecters ie. Diagonal value
        distance[firstSubString][secondSubString] = distance[
            firstSubString - 1
        ][secondSubString - 1]

      else:
        # If last charecters of both substring are not same, we can either insert, remove or replace a charecter
        # We choose minimum possible edit distance of the substrings before performing operation
        # and we add 1 to edit distance for the one operation we need to perform to convert firstString to secondString
        distance[firstSubString][secondSubString] = 1 + min(
            distance[firstSubString][secondSubString - 1],  # Insert
            distance[firstSubString - 1][secondSubString],  # Remove
            distance[firstSubString - 1][secondSubString - 1],  # Replace
        )
  return distance[firstLength][secondLength]

  firstString = input()
  secondString = input()
  print(editDist(firstString, secondString))


"""
Sample Input:
shine
sings
Sample Output:
3
"""
