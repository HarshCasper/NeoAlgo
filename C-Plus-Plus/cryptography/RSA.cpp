/*Program to implement RSA CRYPTOSYSTEM*/
#include<bits/stdc++.h>
using namespace std;

//Function to find greatest comman divisor of two numbers
int gcd(int a, int b) {
    int t;
    while(1) {
        t= a%b;
        if(t==0)
            return b;
        a = b;
        b = t;
    }
}

//Function to find multiplicative Inverse of the number a modulo m
int modInverse(int a, int m){
    a = a%m;
    for (int x=1; x<m; x++)
        if ((a*x) % m == 1)
            return x;
    return a;
}

//Function to find b raised to power n modulo n
int powMod(int b,int p,int n){
    int ans = 1;
    while(p--){
        ans*=b;
        ans%=n;
    }
    return ans;
}

//Driver function
int main() {
    //Input the two variables p and q
    double p;
    double q;
    cout<<"Enter the value of p and q:\t";
    cin>>p>>q;
    //find n = pXq
    double n=p*q;
    //phi(n) = (p-1) X (q-1)
    double phi= (p-1)*(q-1);
    //Input the value of e such that 1<e<phi(n) and e is coprime yo phi(n)
    double e;
    cout<<"Enter the value of e:\t";
    cin>>e;

    // d is inverse of e modulo phi(n)
    double d1=modInverse(e,phi);
    double d=fmod(d1,phi);

    //Here (e,n) is Public Key and d is private key

    //Input the message
    double message;
    cout<<"Enter the message\t";
    cin>>message;

    //[Encrypted Message] c = (message)^e mod n
    double c = powMod(message,e,n);
    //[Decrypted Message] d = c^d mod n
    double m = powMod(c,d,n);
    cout<<"Original Message = "<<message;
    cout<<"\n"<<"p = "<<p;
    cout<<"\n"<<"q = "<<q;
    cout<<"\n"<<"n = pq = "<<n;
    cout<<"\n"<<"phi = "<<phi;
    cout<<"\n"<<"e = "<<e;
    cout<<"\n"<<"d = "<<d;
    cout<<"\n"<<"Encrypted message = "<<c;
    cout<<"\n"<<"Decrypted message = "<<m;
    return 0;
}

//Time complexity : O(p*q)

//Input: p=7, q=11, e=13, message=5

/*Output:
    Enter the value of p and q:     7 11
    Enter the value of e:   13
    Enter the message       5
    Original Message = 5
    p = 7
    q = 11
    n = pq = 77
    phi = 60
    e = 13
    d = 37
    Encrypted message = 26
    Decrypted message = 5
*/