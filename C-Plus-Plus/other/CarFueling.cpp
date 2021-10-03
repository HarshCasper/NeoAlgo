/*
Problem Introduction
You are going to travel to another city that is located 𝑑 miles away from your home city. Your car can travel.
At most 𝑚 miles on a full tank and you start with a full tank. Along your way, there are gas stations at
Distances petrolbunk1,petrolbunk2..... petrolbunk𝑛 from your home city. What is the minimum number of refills needed?
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int


//function to find whether Refueling is possible or not
int car_fueling(ll current_refill,ll max_distance,ll last_refills, ll total_number_of_stops, ll pos[])
{   ll number_of_refills=0;
    while(current_refill<=total_number_of_stops)                          
    {   last_refills=current_refill;
        //condition to check to reach the nearest stop
        while(current_refill<=total_number_of_stops && pos[current_refill+1]-pos[last_refills]<=max_distance)
        {
            current_refill++;
        }
        // if Cannot reach the destination nor the next gas station
        if(current_refill==last_refills)
        {  
            return -1;
        }
        /*
        incrementing number of refills 
        under the condition it is lesser than the total number of stops */
        if(current_refill<=total_number_of_stops)
        { 
            number_of_refills++;
        }
    }
    if(current_refill!=last_refills)
    {
    return number_of_refills;
    }
}


int main()
{
    long long distance,max_distance,total_number_of_stops,i,number_of_refills=0,current_refill=0,last_refills; 
    cout<<"Enter the distance to be travelled:\n";
    cin>>distance;
    cout<<"Enter The miles that the car can travel with full tank:\n";
    cin>>max_distance;  
    cout<<"Enter the number of stops:\n";
    cin>>total_number_of_stops;                         
    long long a[total_number_of_stops+1];              
    a[0]=0;
    cout<<"Enter the postions of the gas stations:\n";                            
    for(i=1;i<=total_number_of_stops;i++)
    {
        cin>>a[i];
    }
    a[total_number_of_stops+1]=distance;
    ll result=car_fueling(current_refill,max_distance,last_refills,total_number_of_stops,a);
    if(result==-1)
    {
        cout<<"Refueling not possible"<<"\n";
    }
    else if(result)
    {
        cout<<"The Number of refills are:"<<result<<"\n";
    }

    
}
   


/* Sample output
Enter the distance to be travelled:
950
Enter The miles that the car can travel with full tank:
400
Enter the number of stops:
4
Enter the postions of the gas stations:
200 375 550 750
The Number of refills are:2
Enter the distance to be travelled:
10
Enter The miles that the car can travel with full tank:
3
Enter the number of stops:
4
Enter the postions of the gas stations:
1 2 5 9
Refueling not possible
*/
