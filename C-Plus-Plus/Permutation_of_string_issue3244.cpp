/* Prmutation means to arrange the elements of an ordered list S into a one-to-one correspondence with S itself. 
   A string of length n has n! permutation. 

   METHOD : Using BACKTRACKING and RECURSION
   The idea is to replace each remaining character with a string with its first letter and get all the remaining character permutations using a repeat (recursive) call.
 */

    Solution :

    #include <bits/stdc++.h> //Header File
    using namespace std;

     //Function to get all the thread permutations provided 'S [left_index...n-1]`
    //contains all the different characters
    void permute(string S, int left_index, int n) 
{
      // base state
    if (left_index == n - 1)
    {
        cout << S << endl; //printing characters
        return;
    }
          // analyze each character of the rest of the string
      for (int right_index = left_index; right_index < n; right_index++)
    {
        //change the character to index `first_index` with the current character
        swap(S[left_index], S[right_index]);        // STL used

        // recur for substring `s[first_index +1, n-1]`
        permute(S, left_index + 1, n);

        // backtrack (restore the thread (string) to its original state)
        swap(S[left_index], S[right_index]);
    }
}
     int main()
    
{
     string S; //initializing a string
     cout<<"Enter the string :";  //Take input from user
     cin>>S;
     int x = S.length(); //Storing the length of string
     cout<<"\nAll the permutation of the string are:\n"; //printing 
     permute(S, 0, x); //calling a function
     return 0;

}

/* OUTPUT:
  Enter the string :ABC                                                                                                           
  All the permutation of the string are:                                                                                          
  ABC                                                                                                                             
  ACB                                                                                                                             
  BAC                                                                                                                             
  BCA                                                                                                                             
  CBA                                                                                                                             
  CAB    */                                                                                                                     All the permutation of the str

/* Time Complexity - O(n*n!) (Length of string is 'n'; For a given string there are n! permutations)
   Space Complexity - O(n*n!) */

