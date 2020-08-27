// KMP Algo searches the indices where pattern is 
// found in given text
// for KMP Algo we need a prerequisite
// which is prefix array which preprocess the
// pattern for longest prefix which is also suffix
#include <stdio.h>
#include <string.h>
int maxm=1e5+1;      // maximum size of an input string
void prefix(char* pat, int patlen, int* pre){
    int i=1, j=0;
    pre[0]=0;
    while(i<patlen){
        if(pat[i]==pat[j]){
            j++;
            pre[i]=j;
            i++;
        }
        else{
            if(j==0){
                pre[i]=0;
                i++; 
                continue;
            }
            j=pre[j-1];
        }
    }
}
void kmp(char* pat,char* txt,int* pre,int patlen,int txtlen){
    int i=0, j=0;
    while(i < txtlen){
        if(txt[i]==pat[j]){
            j++; 
			i++;
        }
        else{
            if(j!=0) j=pre[j-1];
            if(j==0) i++;
            continue;
        }
        if(j>=patlen){
            printf("%d ",i-patlen+1);
            j=pre[j-1];
        }
    }
}
int main(){
    char pat[maxm],txt[maxm];
    printf("Enter the pattern to be searched ");
    scanf("%s",pat);
    printf("Enter the text, where we want to search pattern ");
    scanf("%s",txt);
    int patlen,txtlen;
    patlen=strlen(pat);
    txtlen=strlen(txt);
    int pre[patlen];
    prefix(pat,patlen,pre);
    kmp(pat,txt,pre,patlen,txtlen);
    return 0;
}
/* Sample Input: pat: abcab
                 txt: abcabcab
   Sample Output: 1 4
   Explanation: Taking string indexing from 1, we see that we found pattern
                starting at index 1 and at index 4
*/
