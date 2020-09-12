#include <stdio.h>
#include <string.h>
/*
Manacher's Algorithm is used to the find all the pairs (i,j) such that substring s[i…j] is a palindrome.
*/

int min(int num1, int num2){
    return (num1 > num2 ) ? num2 : num1;
}
int max(int num1, int num2){
    return (num1 > num2 ) ? num1 : num2;
}

int main() {
    char str[10];
    scanf("%s", str);
    int n=strlen(str);
    int d1[n]={}, d2[n]={}; //d1 - odd length palindrome, d2 - even length palindrome
    for(int i=0, l=0, r=-1; i<n; ++i) {
        int k;
        if(i>r)
            k=1;
        else
            k=min(d1[l+r-i],r-i+1);
        while(0<=i-k && i+k<n && str[i-k]==str[i+k]){
            k++;
        }
        d1[i]=k--;
        if(i+k>r){
            l=i-k;
            r=i+k;
        }
    }
    for(int i=0, l=0, r=-1; i<n; ++i){
        int k;
        if(i>r)
            k=0;
        else
            k=min(d2[l+r-i+1],r-i+1);
        while(0<=i-k-1&&i+k<n&&str[i-k-1]==str[i+k]){
            k++;
        }
        d2[i]=k--;
        if(i+k>r){
            l=i-k-1;
            r=i+k ;
        }
    }
    int ans=0;
    printf("Following are the pairs which are palindromes: \n");
    for(int i=0; i<n; ++i){
        int x=d1[i];
        while(x){
            ans=max(ans, 2*x-1);
            printf("%d %d\n", i-x+1, i+x-1);
            x--;
        }
    }
    for(int i=0; i<n; ++i){
        int x=d2[i];
        while(x){
            ans=max(ans, 2*x);
            printf("%d %d\n", i-x, i+x-1);
            x--;
        }
    }
    printf("Length of longest palindromic substring: %d", ans);
    return 0;
}

/*
Time Complexity: O(N)
Space Complexity: O(N)
INPUT
abcba
OUTPUT
Following are the pairs which are palindromes: 
0 0
1 1
0 4
1 3
2 2
3 3
4 4
Length of longest palindromic substring: 5
INPUT
abba
OUTPUT
Following are the pairs which are palindromes: 
0 0
1 1
2 2
3 3
0 3
1 2
Length of longest palindromic substring: 4
*/
