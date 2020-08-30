// C++ recursive function to
// solve tower of hanoi puzzle
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from_rod,
                  char to_rod, char aux_rod)
{
  //takes number of rod and rod labels as input
  // performs tower of hanoi algorithm
  // each update in position of disk is shown in output.
  if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod <<
             " to rod " << to_rod << endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod <<
         " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
    int n; // Number of disks
    cout << "Enter number of disks: ";
    cin >> n;
    
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    
    cout << "All disks have been moved to another rod!!!";
    return 0;
}
