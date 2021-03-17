/*  A permutation is the rearrangement of elements of an ordered list S into a one-to-one correspondence with S itself. 
   A string of length n has n! permutation. 

   APPROACH : Using BACKTRACKING
   The idea is to swap each of the remaining characters in the string with its first character and then find all the permutations of the remaining characters using a recursive call.

   Algorithm:
     Define a string.
     Fix a character and swap the rest of the characters.
     Call the permutation() for rest of the characters.
     Backtrack and swap the characters again. */

   SOLUTION:

 #include <iostream>  //header file
 using namespace std;

// Function to find all permutations of a given string `s[i…n-1]`
// containing all distinct characters

void permutation(string s, int i, int n)
{
    // base condition
    if (i == n - 1)
    {
        cout << s << endl; //printing characters
        return;
    }

    // process each character of the remaining string
    for (int j = i; j < n; j++)
    {
        // swap character at index `i` with the current character
        swap(s[i], s[j]);        // STL `swap()` used

        // recur for substring `s[i+1, n-1]`
        permutation(s, i + 1, n);

        // backtrack (restore the string to its original state)
        swap(s[i], s[j]);
    }
}

int main()
{
    string s = "ABC"; //initializing a string

    cout<<"All the permutation of the string are:\n"; //printing 
    permutation(s, 0, s.length()); //calling a function

    return 0;
}

OUTPUT:
   All the permutation of the string are:                                                                                          
   ABC                                                                                                                             
   ACB                                                                                                                             
   BAC                                                                                                                             
   BCA                                                                                                                             
   CBA                                                                                                                             
   CAB  

   /* The time complexity of the solution is O(n*n!) as there are n! permutations for a string of length 'n' and each permutation takes O(n) time.
   There are n recursions, and the biggest space required for a recursion is n (space of every permutation * n!) */
