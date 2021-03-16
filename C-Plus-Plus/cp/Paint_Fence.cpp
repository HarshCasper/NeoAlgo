/*
___Paint Fence Algorithm___

Problem:
Given a fence with n posts and k colors
Find out the number of ways of painting the fence
such that at most 2 adjacent posts have the same color.

Input:
n : number of posts
k : number of colors

Output:
result: number of ways of painting
        considering the condition above

*/

#include <iostream>
using namespace std;

//function uses permutation logic to output number of possible ways of painting

int paint_fence(int n, int k){          
    if(n<2 || k<(n/2)){
        return -1;
    }
    int total[n-1],same[n-1],diff[n-1];
    same[0]=k;
    diff[0]=k*(k-1);
    total[0]=k*k;
    for(int i=1;i<n-1;++i){
        same[i] = diff[i-1];
        diff[i] = total[i-1]*(k-1);
        total[i] = same[i]+diff[i];
    }
    return total[n-2];
}

int main(){
    int post,color;
    cout<<"Enter n,Number of Posts\n";
    cin>>post;
    cout<<"Enter k,Number of Colors\n";
    cin>>color;
    int result = paint_fence(post,color);
    if(result==-1){
        cout<<"Painting is not possible following the condition\n";
    }
    else{
        cout<<"Number of Possiblities: "<<result<<"\n";
    }
    return 0;
}


/*Sample Input/Output

Enter n,Number of Posts
3
Enter k,Number of Colors
5
Number of Possiblities: 120

Enter n,Number of Posts
10
Enter k,Number of Colors
4
Painting is not possible following the condition

Enter n,Number of Posts
5
Enter k,Number of Colors
3
Number of Possiblities: 180

Time Complexity  O(n)
Space Complexity O(n) 
*/
