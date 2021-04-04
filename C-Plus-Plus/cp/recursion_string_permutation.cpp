// Here I use recursion to find all permutation of a string.
// This method is useful for  non repeated character containing string and small length's strings because its time complaxity is in terms of n! .  

#include<bits/stdc++.h>
using namespace std;

void recursion (string s , int left_index , int right_index){
    if( left_index == right_index ) {
       cout<<s<<"  ";
    }
    // here my approach is to fix a character and find all permutation of next all character 
    // and fixing of characters is done by swaping
    for(int i = left_index ; i <= right_index ; i++) {
        swap(s[left_index] , s[i]) ;
        recursion(s , left_index + 1 , right_index) ; 
        swap(s[left_index] , s[i]) ;  
    }
}

int main() {
    string S ;
    cin>>S;
    recursion(S , 0 , S.size() - 1 ) ;
}

/*  Sample input : ab 
    sample output : ab , ba

    Test cases
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
              edbca  edbac  edabc  edacb  eacdb  eacbd  eadcb  eadbc  eabdc  eabcd  */

/* Time complaxity : O(n * n!) where n is length of string
    Space complaxity : o(n * n!) */