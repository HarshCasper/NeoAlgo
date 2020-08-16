//This program solves the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.
#include<stdio.h>
#include<conio.h>
#define INF 9999
char board[20][20];
int n, count;
int getMarked(int row)
{
  int i;
  for(i=0;i<n;i++)
  {
    if(board[row][i] == 'Q')
    {
      return i;
    }
  }
  return INF;
}
int feasible(int row, int col)
{
int i, tcol;
for(i=0;i<n;i++)
  {
    tcol = getMarked(i);
    if(col==tcol || abs(row-i)==abs(col-tcol))
    {
      return 0;
    }
  }
  return 1;
}
void printSolution()
{
  int i, j;
  printf("\n__Solution %d__\nCoordinates: ", count);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(board[i][j] == 'Q')
      {
        printf("(%d, %d)", i+1, j+1);
      }
    }
  }
  printf("\nBoard: __", count);
  for(i=1;i<=n;i++) 
  { 
    printf("___");
  }
  printf("\n      |  ");
  for(i=1;i<=n;i++) 
  { 
    printf(" %d ", i);
  }
  printf("|\n");
  for(i=0;i<n;i++)
  {
    printf("      |%d ", i+1);
    for(j=0;j<n;j++)
    {
      printf(" %c ", board[i][j]);
    }
    printf("|\n");
  }
  printf("       ‾‾");
  for(i=1;i<=n;i++) 
  { 
    printf("‾‾‾‾");
  }
  printf("\n");
  getch();
}
void nQueens(int row)
{
  int i;
  if(row<n)
  {
    for(i=0;i<n;i++)
    {
      if(feasible(row,i))
      {
        board[row][i] = 'Q';
        nQueens(row+1);
        board[row][i] = '-';
      }
    }
  } 
  else
  {
    count++;
    printSolution();
  }
}
void main()
{
  int i, j;
  clrscr();
  printf("No of Queen (N) = ");
  scanf("%d", &n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      board[i][j] = '-';
    }
  }
  nQueens(0);
  printf("\nTotal Solutions: %d", count);
  getch();
}