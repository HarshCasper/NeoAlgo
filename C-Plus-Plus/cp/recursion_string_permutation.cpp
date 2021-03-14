/*
    Here I use recursion to find all permutation of a string.
    This method is useful for small length's strings because its time complaxity is in terms of n!  
    and for non repeated character in string.
*/
#include<bits/stdc++.h>
using namespace std;

void rec(string s , int l , int r){
    // here l is starting index and r is last index of string
    if( l == r ) {
        // this is base case where recursion is going to stop
        cout<<s<<"  ";
        
    }
    // here my approach is to fix a character and find all permutation of next all character 
    // and fixing of characters is done by swaping
    for(int i = l ; i <= r ; i++) {
        swap(s[l] , s[i]) ;
        rec(s , l+1 , r) ; // after fixing of characters we find all permutation of rest all characters by calling same function
        swap(s[l] , s[i]) ;  // here we get again initial string and again this process is start
    }
}

int main() {
    string S ;
    cin>>S;
    rec(S , 0 , S.size() - 1 ) ;

}

/*
    Input_1:xyz
    Output_1 : xyz  xzy  yxz  yzx  zyx  zxy

    Input_2 : abcde
    Output_2 :abcde  abced  abdce  abdec  abedc  abecd  acbde  acbed  acdbe  acdeb  acedb  
              acebd  adcbe  adceb  adbce  adbec  adebc  adecb  aecdb  aecbd  aedcb  aedbc  
              aebdc  aebcd  bacde  baced  badce  badec  baedc  baecd  bcade  bcaed  bcdae  
              bcdea  bceda  bcead  bdcae  bdcea  bdace  bdaec  bdeac  bdeca  becda  becad  
              bedca  bedac  beadc  beacd  cbade  cbaed  cbdae  cbdea  cbeda  cbead  cabde  
              cabed  cadbe  cadeb  caedb  caebd  cdabe  cdaeb  cdbae  cdbea  cdeba  cdeab  
              ceadb  ceabd  cedab  cedba  cebda  cebad  dbcae  dbcea  dbace  dbaec  dbeac  
              dbeca  dcbae  dcbea  dcabe  dcaeb  dceab  dceba  dacbe  daceb  dabce  dabec  
              daebc  daecb  decab  decba  deacb  deabc  debac  debca  ebcda  ebcad  ebdca  
              ebdac  ebadc  ebacd  ecbda  ecbad  ecdba  ecdab  ecadb  ecabd  edcba  edcab  
              edbca  edbac  edabc  edacb  eacdb  eacbd  eadcb  eadbc  eabdc  eabcd 
*/

/*
    Time complaxity : O(n * n!) where n is length of string
    Space complaxity : o(n * n!)
*/