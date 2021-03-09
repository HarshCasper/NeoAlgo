#include <bits/stdc++.h>
using namespace std;

//This function is used for checking whether a word is present in our array or not
int presentInArray(string &word){
    string arr[] = {"micro","soft","hi","ring","hiring","microsoft"};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        if(arr[i].compare(word) == 0){
            return true;
        }
    }
    return false;
}


//this function is used for storing all the words with spaces
void breakingwords(string str, int n, string ans){
    //Process all wordes one by one
    for(int i=1;i<=n;i++){
        string word = str.substr(0,i);
         
        if(presentInArray(word)){
            if(i==n){
                ans += word;
                cout<<ans<<endl;
                return;
            }
        breakingwords(str.substr(i,n-i),n-i,ans + word +" ");
        }
    }
}


// It will Print all possible word breaks of given string
void BreakWords(string str){
    breakingwords(str,str.size(),"");
}

int main() {

    BreakWords("microsofthiring");
    return 0;
}
