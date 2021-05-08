//DEPTH FIRST SEARCH (DFS) IS PROCESSED BY STARTING VERTEX AND THEN GOING DEEPER UNTIL REQUIRED NODE IS FOUND. IT USES IDEA OF BACKTRACKING.
//SPACE COMPLEXITY OF BFS(BREADTH FIRST SEARCH) IS GREATER DEPTH FIRST SEARCH.
//TIME COMPLEXITY OF DFS IS O(|V|+|E|) WHERE V AND E ARE VERTICES AND EDGES RESPECTIVELY.

#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define visited 2

int number_of_nodes;
int adjancency_matrix[MAX][MAX];
int state_of_graph[MAX]; /*i.e. initial or visited nodes*/

void DFS_Traversal();
void DFS(int v);
void create_graph();

int stack[MAX];
int top = -1;
void push(int v);
int pop();
int isEmpty();

void DFS_Traversal() {
    int vertex;

    for (vertex = 0; vertex < number_of_nodes; vertex++)
        state_of_graph[vertex] = initial;

    printf("\nEnter starting node for Depth First Search Traversal : ");
    scanf("%d", & vertex);
    DFS(vertex);
    printf("\n");
}

void DFS(int vertex) {
    int i;
    push(vertex);
    while (!isEmpty()) /*while stack is not equal to empty stack*/ {
        vertex = pop();
        if (state_of_graph[vertex] == initial) {
            printf("%d ", vertex);
            state_of_graph[vertex] = visited;
        }
        for (i = number_of_nodes - 1; i >= 0; i--) {
            if (adjancency_matrix[vertex][i] == 1 && state_of_graph[i] == initial) /*If adjacent edge is present and it is in initial state*/
                push(i);
        }
    }
}

void push(int vertex) {
    if (top == (MAX - 1)) {
        printf("\nStack Overflow\n");
        return;
    }
    top = top + 1;
    stack[top] = vertex;

}

int pop() {
    int vertex;
    if (top == -1) {
        printf("\nStack Underflow\n");
        exit(1);
    } else {
        vertex = stack[top];
        top = top - 1;
        return vertex;
    }
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

void create_graph() {
    int i, maximum_edges, origin, destination;

    printf("\nEnter number of nodes : ");
    scanf("%d", & number_of_nodes);
    maximum_edges = number_of_nodes * (number_of_nodes - 1);

    for (i = 1; i <= maximum_edges; i++) {
        printf("\nEnter edge %d  (-1 -1 in order to exit) : ", i);
        scanf("%d %d", & origin, & destination);

        if ((origin == -1) && (destination == -1))
            break;

        if (origin >= number_of_nodes || destination >= number_of_nodes || origin < 0 || destination < 0) {
            printf("\nInvalid edge.\n");
            i--;
        } else {
            adjancency_matrix[origin][destination] = 1;
        }
    }
}

int main() {
    create_graph();
    DFS_Traversal();
}


//OUTPUT:
//Enter edge 1  (-1 -1 in order to exit) : 0 1
//Enter edge 2  (-1 -1 in order to exit) : 0 2
//Enter edge 3  (-1 -1 in order to exit) : 1 2
//Enter edge 4  (-1 -1 in order to exit) : 2 0
//Enter edge 5  (-1 -1 in order to exit) : 2 3
//Enter edge 6  (-1 -1 in order to exit) : 3 3
//Enter edge 7  (-1 -1 in order to exit) : -1 -1
//Enter starting node for Depth First Search Traversal : 1
//1 2 0 3
