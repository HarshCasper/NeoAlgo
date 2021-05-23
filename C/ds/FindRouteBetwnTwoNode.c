/* C Program to find route between any two nodes in a graph.
    The problem is solved using depth-first-search.We start with root node,
   and during the traversal , check if the node is found.We mark any node found
   in the course of the algorithm as "already visited" to avoid cycles and
   repetition of nodes */

#include <malloc.h>
#include <stdio.h>

// keeping maximum 5 vertices
#define N 5
// Edge-Structure of a graph
struct Edge {
  int from, to;
};

// Node-Structure
struct Node {
  int dest;
  struct Node *next;
};

// graph with array of head pointers
struct Graph {
  // An array of pointers to Node to represent an adjacency list
  struct Node *head[N];
};

// stack node structure
struct Stack {
  int data;
  struct Stack *next;
};

// insertion at beginning
int push(struct Stack **q, int data) {
  struct Stack *temp;

  temp = (struct Stack *)malloc(sizeof(struct Stack));
  if (temp == NULL) {
    printf("Allocation not possible");
    return -1;
  }
  temp->data = data;
  temp->next = *q;
  *q = temp;

  return 0;
}

// check whether stack is empty or not
int isEmpty(struct Stack *q) {
  if (q == NULL) {
    return 1;
  }
  return 0;
}

// deletion at beginning
int pop(struct Stack **s) {
  struct Stack *q;
  int item;
  if (isEmpty(*s)) {
    printf("\nStack is empty");
  } else {
    q = *s;
    item = q->data;
    *s = q->next;
    free(q);
    return (item);
  }
  return 0;
}

struct Graph *Initialize(struct Graph *g) {
  int v, i;

  g = (struct Graph *)malloc(sizeof(struct Graph));

  // Initialize  adjacency list as empty
  // making head of every adjacency list as empty
  for (i = 0; i < N; i++) {
    g->head[i] = NULL;
  }
  return g;
}

// Adds an edge to the graph
int addEdge(struct Graph *graph, int from, int to) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->dest = to;

  // point new node to the head
  newNode->next = graph->head[from];

  // point head pointer to the new node
  graph->head[from] = newNode;
  return 0;
}

// Find Route between two points in a graph
int FindRoute(struct Graph *g, int start, int end) {
  struct Stack *head = NULL;
  int *status;
  int cur, i, v1;
  int flag = 0;
  struct Node *temp;
  status = (int *)malloc((N) * sizeof(int));
  for (i = 0; i < N; i++) {
    status[i] = 0;
  }
  // Initialize stack;
  push(&head, start);
  while (!isEmpty(head)) {
    cur = pop(&head);
    if (status[cur] == 0) {
      status[cur] = 1;
    }

    if (cur == end) {
      flag = 1;
      break;
    }
    // Iterate for all values of current
    temp = g->head[cur];
    while (temp) {
      v1 = temp->dest;

      if (status[v1] == 0) {
        push(&head, v1);
      }
      temp = temp->next;
    }
  }
  if (flag) {
    // route available
    printf("\nRoute Available from %d to %d in the graph", start, end);
  } else {
    // route not available
    printf("\n Route Not Available from %d to %d in the graph", start, end);
  }

  return 0;
}

// print the details of graph
void dispGraph(struct Graph *graph) {
  int v;
  for (v = 0; v < N; ++v) {
    struct Node *traverse = graph->head[v];
    while (traverse) {
      printf("(%d -> %d) ", v, traverse->dest);
      traverse = traverse->next;
    }
    printf("\n");
  }
}

int main() {

  struct Graph *g;
  struct Edge e[100];
  int i, n, from, to;

  struct Graph *graph = Initialize(g);

  printf("\nEnter the no of edges in the graph:");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("\nEnter the edge from-> to:");
    scanf("%d%d", &from, &to);
    addEdge(graph, from, to);
  }

  printf("\nThe Adjacency list of the Graph is:\n");
  dispGraph(graph);

  printf("\nEnter the start and end to find route available/not-available:\n");
  scanf("%d %d", &from, &to);
  FindRoute(graph, from, to);
  return 0;
}

/*
  Sample input/output:
  Enter the no of edges in the graph:7
  Enter the edge from-> to:0 1

  Enter the edge from-> to:0 4

  Enter the edge from-> to:1 2

  Enter the edge from-> to:1 3

  Enter the edge from-> to:1 4

  Enter the edge from-> to:2 3

  Enter the edge from-> to:3 4

  The Adjacency list of the Graph is:
  (0 -> 4) (0 -> 1)
  (1 -> 4) (1 -> 3) (1 -> 2)
  (2 -> 3)
  (3 -> 4)

  Enter the start and end to check for route available/not-available:
  0 4

  Route Available from 0 to 4

  Time complexity: O(n) for finding the route
  Space complexity: O(n)
 */
