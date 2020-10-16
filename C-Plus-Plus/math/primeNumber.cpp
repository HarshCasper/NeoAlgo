// This program will generate prime numbers between two given numbers within o(n) time.

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int main(){
    

    int t{},limit{}, a{};                    // number of test cases
    cin>>t;
    vector<int> limits{};       // vector to store upper and lower limits.
    for(int i{}; i<t*2; i++){
        cin>>limit;              // taking limits
        limits.push_back(limit);
    }

    cout<<endl;
    while (t > 0)
    {
        int root{}, i{}, j{}, k{};
        for(i = limits[a]; i<limits[a+1]+1; i++){
            j = sqrt(i)+1;
            for(k = 2; k<j; k++){
                if (i%k == 0)
                    break;
            }
            if(k == j and i!=1){
                cout<<i<<endl;
            }
        }
        cout<<endl;

        a +=2;
        t--;
            
    }
    

    return 0;
    
}
