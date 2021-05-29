/*Prim's algorithm is a minimum spanning tree algorithm that takes a graph as input and finds 
the subset of the edges of that graph which. form a tree that includes every vertex. 
has the minimum sum of weights among all the trees that can be formed from the graph.
(issue-3304)*/
#include<bits/stdc++.h> 
/*This includes functions like strlen and strcpy,It's the C++ version of header from C*/
using namespace std;
int operation(int array[] , int row, int coloumn, int graph[4][4]); 
#define number 4
/* separate function is declared to form process and output
which takes 2 for loops with min val of vertex displays output 
in 2 columns where Weight of ele and Edge of graph*/
int operation(int array[], int row, int coloumn, int graph[4][4]) {
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
 cout<<"enter the elements into graph array "<< endl ;
 /* taking the inputs for graph in form of loop
 which is of having number(of rows and coloumns) */
  int row , coloumn; 
int graph[number][number];
        for (int i =0; i< number ; i++){
    for(int j=0 ; j< number ; j++){
        cin>>graph[i][j];
    } }
cout <<"Weight of ele,"<< " "<<"Edge of graph" <<"\n";
/* iterate while loop till all edges are lesser than num-1 */
  while ( number - 1 > all_edges) {
    row = 0,coloumn = 0;
    operation(array,row,coloumn,graph);
    all_edges++;
    }
  return 0;
}
/* input:
enter the elements into graph array                                                                                                                                                  
1 4 78 15                                                                                                                                                                            
1 75 48 6                                                                                                                                                                            
45 7 8 36                                                                                                                                                                            
2 4 67 59   
output:
Weight of ele, Edge of graph                                                                                                                                                         
4  0 - 1                                                                                                                                                                             
6  1 - 3                                                                                                                                                                             
48  1 - 2 
time_complexity_O(ElogV) where v no of vertices and e no of edges

*/
