#include<bits/stdc++.h>
using namespace std;

void pairStar(char input[])
{
	int size=0,i;
	while(input[size] != '\0')
		size++;
	if (input[0]=='\0' || size==0)
		return;
    if (input[0]==input[1])
    {  
        input[size+1]='\0';
        for (int i=size-1; i>=1; i--){
            input[i+1]=input[i];
        }
        input[1]='*';
        pairStar(input+1);
    }
    else{
        pairStar(input+1);
    }
	
	
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}

/* 
sample input 1-
hello
sample output 1 -
hel*lo

Time complexity- O(n)
*/
