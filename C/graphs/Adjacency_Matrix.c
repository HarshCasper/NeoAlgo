/*
This code inputs an adjacency matrix from the user. Matrix includes 1 for the vertices having an adge, and 0 otherwise. 
Functions defined are Input, Delete and Print which carry out the respective functions.
The output will be show the parent vertex and their adjacent vertices.
I use a pointer array of size 5. 
*/

#include<stdio.h>
#include <stdlib.h>

//This is the structure defining the 2-D array of size 5*5
typedef struct AdjMat{
	int arr[5][5];
} AdjMat;

//This function inserts the value into the pointer array
void insert(AdjMat *g, int parent, int val)
{
	//This is to make sure that both the vertices are connected.
	//Array element at a position [i,j] and [j,i] will be made 1
	g->arr[parent][val]= 1;
	g->arr[val][parent]= 1;
}

//This fuction deletes the value, removes its edge connecting all the vertices as well as it's connection with all the other vertices
void delete(AdjMat *g, int val)
{
	int flag=0;
	for(int i=0;i<5;i++)
	{
		if(g->arr[i][val]==1){ //Checks whether an edge is present connecting the two vertices
			g->arr[i][val]=0;
			flag=1;    //Tells the user that if that node was found and deleted
		}

		//Same method as the above commands, repeating for the [j,i]th position
		if(g->arr[val][i]==1){ 
			g->arr[val][i]=0;
			flag=1;
		}
	}
	if(flag==0) //To see if the node is present or not
		printf("Node %d is not found in the matrix\n", val);

}


//This function prints the matrix
void print(AdjMat *g)
{
	int flag=0, f=0, edges=0;

	//the loops check the whole matrix
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(g->arr[i][j]==1)
			{
				//this tells us that the node has edges, or vertices connected to it
				f=1; 

				// this tells us that matrix is not empty
				edges=1; 
				
				//This tells us if the parent node has been printed
				if(flag==0){ 
					printf("%d->", i);
					flag=1;
				}
				printf(" %d", j); //prints the adjacent vertices
			}
		}
		flag=0;
		if(f==1) 
			//goes to next line if the adjcent vertices are print and doesnt if the node doesnt have any adjacent vertices.
		    printf("\n");
		f=0;
	}
	if(edges==0)
		printf("No edges\n");
}

//Main function
void main()
{
	int choice, parent, val;
	//Initialise the pointer array
	AdjMat *g= (AdjMat*)malloc(sizeof(AdjMat*)*5);

	//Initialise all th elements as 0
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			g->arr[i][j]=0;

	printf("Enter the choice\n1.Insert\n2.Delete\n3.Print\n");
	scanf("%d",&choice);

	//Loops till the user wants to exit 
	while(choice!=4){
	switch(choice)
	{
		//for inserting any node
		case 1:
			printf("Enter the parent and the value\n");
			scanf("%d %d", &parent, &val);
			insert(g, parent, val);
			break;
		
		//for deleteing any node
		case 2: 
			printf("Enter the val to be deleted\n");
			scanf("%d", &val);
			delete(g, val);
			break;

		//for printing the adjacency matrix
		case 3:
			print(g);
			break;
	}
	
	//User enters the choice 
	printf("Choice? ");
	scanf("%d", &choice);
}

}


/*
Sample Input:
1 2
1
1 4
1 
2 4
1
2 3
1 
2 4
1 
3 2
1 
3 4
1
4 1
1
4 2
1
4 3
2
2
3
4

Output: 
1-> 4
3-> 4
4-> 1 3

Time Complexity:  Since the matrix is of size n, 
				  O(n^2)
Space Complexity: O(n^2)
*/

