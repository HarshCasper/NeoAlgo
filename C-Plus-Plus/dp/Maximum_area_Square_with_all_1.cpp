#include<bits/stdc++.h>
using namespace std;

int main()
 {
    int t;
    cout<<"Enter the testcase \n";
    cin>>t;
    while(t--){
        int n,m,i,j;
        cout<<"Enter the row and column \n";
        cin>>n>>m;
        cout<<"Enter Matrix Elements \n";
        int mat[n][m],sat[n][m],maxx=0;
        memset(sat,0,sizeof(sat));
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>mat[i][j];
        for(i=0;i<m;i++)
        {
            sat[0][i]=mat[0][i];//copy first row from original array
        }
        for(i=0;i<n;i++){
            sat[i][0]=mat[i][0];//copy first col from original array
        }
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                if(mat[i][j]==1){//if element is 1 then
                //add 1+min from up(i-1,j),left(i,j-1),top(i-1,j-1)
                    sat[i][j]=min(min(sat[i-1][j],sat[i][j-1]),sat[i-1][j-1])+1;
                }
            }
        }
        //find the maximum element from the dp which is our side of largest square
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
               // cout<<sat[i][j]<<" ";
                if(sat[i][j]>maxx)
                maxx=sat[i][j];
            }
           // cout<<endl;
        }
        cout<<"Maximum area is:"<<maxx*maxx<<endl;
    }
    return 0;
}

/*
Enter the testcase
1
Enter the row and column
4 4
Enter Matrix Elements
1 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1
Maximum area is:9

Time Complexity:O(m*n) 
Space complexity:O(m*n) 
*/
