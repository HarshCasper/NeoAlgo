/*Flood Fill Algorithm determines the area connected to given node in multidensioanl array

Problem Statement: To fill connected, similarly-colored areas with different color.
Idea: Start from current source node and replace its color with the replacement color
and recursively explore all valid neighbours and replace their color as well.

Input for algorithm: matrix, start node, target color, replacement color.

Time Complexity:O(M.N)*/

#include<bits/stdc++.h>
#define M 10
#define N 10
using namespace std;

//for processing 8 directions 
int row[]={-1,-1,-1,0,0,1,1,1};
int col[]={-1,0,1,-1,1,-1,0,1};

//to check the valid neighbours
bool safe(char matrix[M][N],int start_x,int start_y,char target){
	return(start_x>=0 && start_y>=0 && start_x<M && start_y<N && matrix[start_x][start_y]==target);
}

void floodFill(char matrix[M][N],int start_x,int start_y,char target,char replacement){
	//replacing color of current cell
	matrix[start_x][start_y]=replacement;
	//processing all 8 neighbours recursively
	for(int k=0;k<8;k++){
		if(safe(matrix,start_x+row[k],start_y+col[k],target)){
			floodFill(matrix,start_x+row[k],start_y+col[k],target,replacement);
		}
	}	
}

int main(){
	char matrix[M][N];
	//input for matrix
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin>>matrix[i][j];
		}
	}
	//starting node
	int start_x,start_y;
	cin>>start_x>>start_y;
	//color to be replaced
	char target_color;
	cin>>target_color;
	//color to be filled in place of target
	char replacement_color;
	cin>>replacement_color;

	floodFill(matrix,start_x,start_y,target_color,replacement_color);

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

/*Sample input:
Y Y Y G G G G G G G 
Y Y Y Y Y Y G X X X
G G G G G G G X X X
W W W W W G G G G X 
W R R R R R G X X X
W W W R R G G X X X
W B W R R R R R R X
W B B B B R R X X X
W B B X B B B B X X
W B B X X X X X X X
3 9
X
C

Sample output:
Y Y Y G G G G G G G 
Y Y Y Y Y Y G C C C 
G G G G G G G C C C 
W W W W W G G G G C 
W R R R R R G C C C 
W W W R R G G C C C 
W B W R R R R R R C 
W B B B B R R C C C 
W B B C B B B B C C 
W B B C C C C C C C 
*/