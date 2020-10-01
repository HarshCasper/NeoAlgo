#include<stdio.h>
#include<stdlib.h>

#define N 1000  
  
// This function returns true if woman 'w' prefers man 'm1' over man 'm' 
int wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1,int a) 
{ 
    // Check if w prefers m over her current engagment m1 
    for (int i = 0; i < a; i++) 
    { 
        // If m1 comes before m in lisr of w, then w prefers her 
        // cirrent engagement, don't do anything 
        if (prefer[w][i] == m1) 
            return 1; 
  
        // If m comes before m1 in w's list, then free her current 
        // engagement and engage her with m 
        if (prefer[w][i] == m) 
           return 0; 
    } 
} 
  
void stableMarriage(int prefer[2*N][N],int a) 
{ 
    int size=a;
    int wPartner[N];
    for(int i=0;i<N;i++)
    wPartner[i]=-1;
  
    // An array to store availability of men.
    int mFree[N]={0}; 
    int freeCount = a; 
  
    // While there are free men 
    while (freeCount > 0) 
    { 
        // Pick the first free man (we could pick any) 
        int m; 
        for (m = 0; m < a; m++) 
            if (mFree[m] ==0) 
                break; 
        for (int i = 0; i < a && mFree[m] == 0; i++) 
        { 
            int w = prefer[m][i]; 
  
            // The woman of preference is free, w and m become partners 
            if (wPartner[w-a] == -1) 
            { 
                wPartner[w-a] = m; 
                mFree[m] = 1; 
                freeCount--; 
            } 
  
            else  // If w is not free 
            { 
                // Find current engagement of w 
                int m1 = wPartner[w-a]; 
  
                // If w prefers m over her current engagement m1, 
                // then break the engagement between w and m1 and 
                // engage m with w. 
                if (wPrefersM1OverM(prefer, w, m, m1,a) == 0) 
                { 
                    wPartner[w-a] = m; 
                    mFree[m] = 1; 
                    mFree[m1] = 0; 
                } 
            } 
        } 
    } 
    // Print the solution  
    printf("W   M\n");
    for (int i = 0; i < a; i++) 
        printf(" %d    %d\n",i+a,wPartner[i]);
      
} 
  
// Driver program to test above functions 
int main() 
{
    int testcases;
    scanf("%d",&testcases);
    
    while (testcases-->0)
    {
        int a;
        scanf("%d",&a);
        int prefer[2*N][N];
        for(int i=0;i<2*a;i++)
        {
            for(int j=0;j<a;j++)
            {
                int jj;
                scanf("%d",&jj);
                //printf("F");
                prefer[i][j]=jj;
            }
        }
        stableMarriage(prefer,a); 
    }
    return 0; 
} 