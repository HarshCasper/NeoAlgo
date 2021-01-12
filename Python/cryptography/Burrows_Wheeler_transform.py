'''
Burrows Wheeler Transform(BWT): BWT is a string compression algorithm
that can be used to simply encrypt strings just by cyclic operations.
It is used in zip format files, Linux, Internet Protocols to even research.

Motivation:
https://www.youtube.com/watch?v=4WRANhDiSHM&list=TLPQMjcxMjIwMjCzl4040phelQ&index=2
Method: There are numerous ways of implementing this algorithm.
Here simple array operations are used, so that the idea of algorithm
can be easily conveyed and understood.

N = length of input string
Time Complexity:  O(N2Log(N))(NLog(N) for sorting and N for iteration)
Space Complexity: O(N)(for cyclic rotations of orignal string)
Argument: String (Orignal string)
Return : String (BWT compressed string)
'''


def bwt(orignal_string):

    # Add '$' to denote end of the orignal string, which is needed to invert
    # and obtain the orignal string
    orignal_string += "$"

    # Roatating orignal string letter by letter and storing cyclic rotations
    bwt_rotations = sorted(orignal_string[i:] + orignal_string[:i]
                           for i in range(len(orignal_string)))

    # Last column letters of the bwt_rotations has a special charecteristic
    # which is used to get back orignal string.
    last_column = [row[-1:] for row in bwt_rotations]

    # Return last_column as compressed bwt_string
    bwt_string = "".join(last_column)
    return bwt_string


def invert_bwt(compressed_string):

    # Store length of compressed_string
    length = len(compressed_string)

    # Intialise bwt_rotations as empty strings
    bwt_rotations = [""] * length

    # Looping length times to get all the cyclic rotations(permutations)
    # Roatating compressed_string letter by letter and storing cyclic rotations
    for i in range(length):
        bwt_rotations = sorted(
            compressed_string[i] + bwt_rotations[i] for i in range(length))

    # Finding the orignal string, knowing it ends with '$'
    for row in bwt_rotations:
        if row[-1] == "$":
            inverted_string = "".join(row)
            break
    return inverted_string


# Driver Code
if __name__ == '__main__':
    print("Enter a string to compress using BWT:")
    bwt = bwt(input())
    print("BWT compressed string: ", bwt.replace("$", ""))
    print("Inverted bwt to get orignal string: ",
          invert_bwt(bwt).strip("$"))


'''
Sample Input:
Enter a string to compress using BWT:
neoalgo

Sample Output:
BWT compressed string:  oonlage
Inverted bwt to get orignal string:  neoalgo
'''
