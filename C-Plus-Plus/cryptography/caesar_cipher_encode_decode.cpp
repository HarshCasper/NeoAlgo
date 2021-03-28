#include<bits/stdc++.h> //includes all the necessary header files
using namespace std;
/* Encrypts the plain text message into a cipher 
text by simply replacing each letter of a given 
text by a letter '3' places down the alphabet. */

void caesarfun(int k)   //function to encrypt or decrypt the string
{
    char s[100];
    cout<<"Enter the string:";
    cin.clear();
    cin.sync();
    cin.getline(s,100);     //used getline() to input strings containing spaces
    for(int i=0;s[i]!='\0';i++)
    {
        int m=s[i];

        if(m>96&&m<124){
            m=m-96;
            m=(26+(m+k))%26+96;
            s[i]=(char)m;
        }
        else if(m>64&&m<91)
        {
            m=m-64;
            m=(26+(m+k))%26+64;
            s[i]=(char)m;
        }
        else continue;
    }
    cout<<"Output is:";
    puts(s);
}

int main()
{
    int k,a;
    cout<<"-------Caesar Cipher Encoder/Decoder-------\n";
    invalid :
    cout<<"->Press 1 to encode string\n->Press 2 to decode string\n";
    cin>>a;
    switch(a)
    {
        case 1:
        break;
        
        case 2 :
        break;

        default:
        cout<<"Invalid Input!!!!\n";
        goto invalid;
    }
    cout<<"Enter the key:";
    cin>>k;

    if(a==1)
    k=k;
    else if(a==2)
    k=-k;

    caesarfun(k);

    return 0;
}