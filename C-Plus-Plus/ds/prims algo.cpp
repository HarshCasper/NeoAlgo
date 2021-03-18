/*Prim's algorithm is a minimum spanning tree algorithm that takes a graph as input and finds 
the subset of the edges of that graph which. form a tree that includes every vertex. 
has the minimum sum of weights among all the trees that can be formed from the graph.
(issue-3304)*/
#include <iostream>
#include <cstring>
/*This includes functions like strlen and strcpy,It's the C++ version of header from C*/
using namespace std;
int operation(int array[] , int row, int coloumn, int graph[9][9]); 
#define number 9
/* separate function is declared to form process and output
which takes 2 for loops with min val of vertex displays output 
in 2 columns where Weight of ele and Edge of graph*/
int operation(int array[], int row, int coloumn, int graph[9][9]) {
        int least_val = 100;
        for (int index_x = 0 ; index_x < number; index_x ++) {
      if (array[index_x]) {
        for (int index_y = 0 ; index_y < number; index_y++) {
          if (!array[index_y] && graph[index_x][index_y])  {  
            if (least_val> graph[index_x][index_y] ){
             least_val = graph[index_x][index_y];
             row= index_x , coloumn= index_y;
            } } } } }
    cout << graph[row][coloumn]<<"  "<<row<< " - " << coloumn << endl;
    array[coloumn] = true;
    }
/* in main we give inputs to graph array and calls operation function */ 
int main() {
  int all_edges;
   int array[number];
/*memset Sets the first num bytes of the block of memory 
pointed by ptr to the specified value faster than loop*/
  memset(array, false, sizeof(array));
  all_edges = 0;
  array[0] = true;
  int row , coloumn; 
int graph[number][number] = {
  {5, 7, 85, 2, 1, 58, 45,1,7},
  {54 , 0, 75, 9, 2, 46 ,17,4,5},
  {63, 16, 0, 41, 66 , 48,36,48,84},
  {7, 9, 5, 0,65, 1,3,87,59 },
  {6, 72, 76, 75,48,95,49,46,47},
  {19, 25,65,39,17,24,28,12,14},
  {76,89,94,15,14,28,27,78,74},
  {1,75,48,75,48,63,15,4,8},
  {3,37,36,18,25,2,9,29,43}
};
cout <<"Weight of ele,"<< " "<<"Edge of graph" <<"\n";
/* iterate while loop till all edges are lesser than num-1 */
  while ( number - 1 > all_edges) {
    row = 0,coloumn = 0;
    operation(array,row,coloumn,graph);
    all_edges++;
    }
  return 0;
}
/* input: {
  {5, 7, 85, 2, 1, 58, 45,1,7},
  {54 , 0, 75, 9, 2, 46 ,17,4,5},
  {63, 16, 0, 41, 66 , 48,36,48,84},
  {7, 9, 5, 0,65, 1,3,87,59 },
  {6, 72, 76, 75,48,95,49,46,47},
  {19, 25,65,39,17,24,28,12,14},
  {76,89,94,15,14,28,27,78,74},
  {1,75,48,75,48,63,15,4,8},
  {3,37,36,18,25,2,9,29,43}
};
output :Weight of ele, Edge of graph                                                                                                                                                         
1  0 - 4                                                                                                                                                                             
1  0 - 7                                                                                                                                                                             
2  0 - 3                                                                                                                                                                             
1  3 - 5                                                                                                                                                                             
3  3 - 6                                                                                                                                                                             
5  3 - 2                                                                                                                                                                             
7  0 - 1                                                                                                                                                                             
5  1 - 8 
time_complexity_O(ElogV) where v no of vertices and e no of edges

*/
