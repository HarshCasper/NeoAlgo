#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,j,c=0;
    string s;
    char i;
    cin>>n;
    s=to_string(n)+to_string(n*2)+to_string(n*3);
    int count = 0;
        for(i = '1'; i <= '9'; i++)
        {
            int c = 0;
            for(int j = 0; s[j]!=NULL; j++)
            {
                if(i == s[j])
                    c++;
            }
            if(c == 1)
                count++;
        }
         if(count == 9)
         {
                cout<<"Fascinating number";
                
            }
            else
            {
                cout<<"Not Fascinating number";
            }
        return 0;

}
