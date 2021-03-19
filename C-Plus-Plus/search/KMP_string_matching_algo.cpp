/* Code implementaion of KMP (Knuth Morris Pratt) Pattern Searching algorithm. O(N) complexity algoritm
    example1:- string A=CODEHEAT
               string B=HEAT
              
    string B can be found in string A hence it returns index 4 as string B starts from index 4.
        
    
   example2:- string A=CODEHEAT
              string B=ZAH
              
        string B can't  be found in string A hence it returns index -1 as result.
        
*/

#include <bits/stdc++.h>
using namespace std;

/*pre-process pattern and prepare an integer array lps[] 
that tells us the count of characters to be skipped.*/
void computeLPS(string B, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 

    lps[0] = 0; // lps[0] is always 0 

    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (B[i] == B[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 

            if (len != 0) { 
                len = lps[len - 1]; 

            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

void search(string A,string B) 
{ 
    int M = B.length(); 
    int N = A.length();
    
   bool s=false;
    /* create lps[] to  hold the longest prefix suffix 
     values for pattern */
     
    int lps[M]; 

    // Preprocess the pattern (calculate lps[] array) 
    computeLPS(B, M, lps); 

    int i = 0; // index for B[] 
    int j = 0; // index for A[] 
    while (i < N) { 
        if (B[j] == A[i]) { 
            j++; 
            i++; 
        } 

        if (j == M) { 

            s=true;
            cout<<"string found at index "<<i-j<<"\n";
            j = lps[j - 1]; 
        } 
        else if (i < N && B[j] != A[i]) { 

            if (j != 0) 
               {
                    j = lps[j - 1]; 
               }

            else
            {
                i = i + 1; 
            }

        } 
    } 

    if(s==false)
    {
        cout<<"String couldn't be found in the main string\n";
    }

} 

int main()
{

    string A,B;
    cout<<"Enter the main string\n";
    cin>>A;
    cout<<"Enter the string to be searched\n";
    cin>>B;
    search(A,B);

    return 0;
}
/*
   Time and Space Complexity:-
   Time Complexity:-O(N)
   Space Complexity:-O(N) (For precomputation)
   
   Input/Output format:-
   
   INPUT:- Enter the main string
           
           TessaractCoding
           
           Enter the string to be searched
           
           ract
           
  OUTPUT:- string found at index 5.       
           
*/
