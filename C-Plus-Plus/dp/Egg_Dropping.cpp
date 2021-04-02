//Egg Dropping problem
/*
The Egg Dropping Problem: There is a building with k floors. You are given n eggs.

An egg dropping from any floor is termed a “trial”. After a dropping, an egg can either survive or
break. A broken egg cannot be used whereas a survived egg can be used for another trial. All eggs are
identical, i.e. effect must be same for all eggs.

A floor is called the critical floor if an egg breaks from that floor and above but does not break from
any floor below that one. We assume that if an egg survives a fall, it survives a shorter fall. And if an
egg breaks from some floor, then it would break from higher floor also.

Given n and k, you have to find the minimum number of trials in the worst case.
*/

#include <bits/stdc++.h> 
using namespace std;

int egg,flr;
int **table= NULL;
int min_probes=0;

void input()
{
	cin>>egg;
	cin>>flr;
	table=new int*[flr+1];		//Initializing memory for DP Table
	for(int i = 0; i <= egg; ++i)
      table[i] = new int[flr+1];
  
}
int find_min_probes(int e,int f)
{   

	if(e==1)
		return f;

    if(f==0||f==1)
		return  f;
    
    int probes=INT_MAX;
    for(int k=1;k<=f;k++)
    {
		int temp=1+max(find_min_probes(e-1,k-1),find_min_probes(e,f-k));
        probes=min(probes,temp);
    }
   	return probes;
}

void display()
{
	cout<<"*************** Egg Droping Problem *****************"<<endl;
	cout<<endl<<"Number of eggs are: "<<egg;
	cout<<endl<<"Number of floors are: "<<flr<<endl;
	cout<<"\nMinimum number of trials in worst case with "<<egg<<" eggs and "<<flr<<" flrs are: "<<min_probes<<endl<<endl;
}

int main() 
{ 
    input(); 
    min_probes = find_min_probes(egg,flr);
	display();
	return 0;
} 

/*
Input:
2
10

Output:
*************** Egg Droping Problem *****************

Number of eggs are: 2
Number of floors are: 10

Minimum number of trials in worst case with 2 eggs and 10 flrs are: 4
*/