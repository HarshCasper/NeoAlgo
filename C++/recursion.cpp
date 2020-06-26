#include<iostream>
using namespace std;
void towerOfHanoi(int n,char src,char dest,char helper){
    //Base Case
    if(n==0){
        return;
    }
    //Rec Case
    //First step N-1 disk move from src to helper
    towerOfHanoi(n-1,src,helper,dest);
    cout<<"Move"<<n<<"disk from"<<src<<"to"<<dest<<endl;
    towerOfHanoi(n-1,helper,dest,src);



}
int main(){
    int ;
    cin>>n;
    towerOfHanoi(n,'A','C','B');
    return 0;
    
}