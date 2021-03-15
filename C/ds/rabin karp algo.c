/*  C implementation of Rabin Karp Algorithm issue-2943*/
#include<stdio.h> 
#include<string.h> 
  
#define d 256 
  

void search(char pat[], char txt[], int q) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
    int i, j; 
    int p = 0; 
    int t = 0; 
    int h = 1; 
  
    /*The value of h would be "pow(d, M-1)%q"*/ 
    for (i = 0; i < M-1; i++) 
        h = (h*d)%q; 
  
    
    
    for (i = 0; i < M; i++) 
    { 
        p = (d*p + pat[i])%q; 
        t = (d*t + txt[i])%q; 
    } 
  

    for (i = 0; i <= N - M; i++) 
    { 
  
        /* Check the hash values of current window of text*/ 
         /* and pattern. If the hash values match then only */
      /*check for characters on by one */
        if ( p == t ) 
        { 
            /* Check for characters one by one */
            for (j = 0; j < M; j++) 
            { 
                if (txt[i+j] != pat[j]) 
                    break; 
            } 
  
             
            if (j == M) 
                printf("Pattern found at index %d \n", i); 
        } 
  
        
        if ( i < N-M ) 
        { 
            t = (d*(t - txt[i]*h) + txt[i+M])%q; 
  
            /*We might get negative value of t, converting it to positive */
            if (t < 0) 
            t = (t + q); 
        } 
    } 
} 
  
/* Driver Code */
int main() 
{ 
    char txt[] = "THIS IS A TEST TEXT"; 
    char pat[] = "TEST"; 
    
      // A prime number 
    int q = 101;  
    
      // function call 
    search(pat, txt, q); 
    return 0;
}

/*
Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12*/