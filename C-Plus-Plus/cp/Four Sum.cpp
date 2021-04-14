#include <bits/stdc++.h>
using namespace std;
struct SUM
{
   int a;
   int b;
};
int main () {
typedef vector<int> VI;
   VI l(5);
   l[0] = 1;
   l[1] = 2;
   l[2] = -1;
   l[3] = -2;
   l[4] = 5;
   l[5] = 6;
sort(l.begin(), l.end());
 int sumTo = 0;   typedef multimap<int, SUM> Table;
typedef pair<int,SUM> PairSUM;
   Table myTbl;
   for (int i = 0; i < l.size(); ++i)
   {
      for (int j = i+1; j < l.size(); ++j)
      {
         int val = l[i] + l[j];
         // A is always less than B
         SUM ent = {i, j};
myTbl.insert(PairSUM(val,ent));
      }
   }
pair<Table::iterator, Table::iterator> range;
// Start at beginning of array
   for (Table::iterator ita = myTbl.begin();ita != myTbl.end();++ita)
   {
      int lookFor = sumTo - ita->first;
      // Find the complement
      range = myTbl.equal_range(lookFor);
// Const bound
      for (Table::iterator itb = range.first;itb != range.second;++itb)
      {
         if (ita->second.a == itb->second.a || ita->second.b == itb->second.b)
         {
            // No match
            }
         else
         {
            // Match
            cout << l[ita->second.a] << " " << l[itb->second.a] << " "
                 << l[ita->second.b] << " " << l[itb->second.b] << endl;
                 return 0;
         }
      }
   }
return 0;
}
