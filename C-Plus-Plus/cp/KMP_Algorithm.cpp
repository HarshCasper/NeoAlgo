#include <iostream>
using namespace std;

int * getlps(char T[]){     //lps here holds longest prefix suffix
    int i;
  for(i=0;T[i]!='\0';i++);
  int len=i;                //Length
    int * lps= new int[len];
    lps[0]=0;
     i=1;   //index for 
    int j=0;
    while(i<len){
        if(T[i] == T[j]){     //where T is a pattern
            lps[i]=j+1;
            i++;
            j++;
        }else{      //mismatch after j matches
            if(j!=0){
                j=lps[j-1];
            }else{
                lps[i]=0;  //because j=0
                i++;
            }
        }
    }
    return lps;
}

int KMPSearch(char S[], char T[]) {    //Function to return final index where we found the substring 
   int i,j;
    for(i=0;S[i]!='\0';i++);
	int slen=i;            //Length of S
        for(j=0;T[j]!='\0';j++);
	int tlen=j;            //Length of T
     i=0;
     j=0;
    int * lps=getlps(T);
    
    while(i<slen&&j<tlen){
        if(S[i]==T[j]){     //means both are equal
            i++;
            j++;
        }else{         // (S[i] != T[j]) 
            if(j!=0){
                j=lps[j-1];   //do not increment i here
            }else{     //if (j==0)
                i++;
            }
        }
    }
    if(j==tlen){
        return i-j;
    }
    return -1;   //Pattern is not found
}



int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;          //Print the final answer
}


