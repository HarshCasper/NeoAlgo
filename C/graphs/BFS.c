

#include<stdio.h>
#include<conio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v) {
	visited[v]=1;
	q[++r]=v;
	while (f<=r)
	{
		v=q[f++];
		printf("%d", v);
		for (i=1;i<=n;i++)
		  if(a[v][i] && !visited[i])
		  {
		     q[++r]=i;
		     visited[i]=1;
		  }
	}
}
void main() {
	int v;
	clrscr();
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		q[i]=0;
		visited[i]=0;
	}
	printf("\n Enter graph data in matrix form:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
	bfs(v);
	getch();
}

/*
Enter the number of vertices:4
Enter graph data in matric form:
0110
1011
1100
0100
Enter the starting vertex:1
1     2      3      4
*/

