/*
 Write Java programs to
 Implement All-Pairs Shortest Paths problem using Floyd's algorithm.

 */
import java.util.Scanner;
public class Floyds {

    public static void floyd(int a[][],int n)
    {
        int i,j,k;
        int d[][]=new int[10][10];
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                d[i][j]=a[i][j];
            }
        }
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        System.out.println("\nThe distance matrix is\n");
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                System.out.print(+d[i][j]+"\t");
            }
            System.out.println("\n");
        }
    }
    public static int min (int a,int b)
    {
        if(a<b)
            return a;
        else
            return b;
    }
    public static void main(String args[])
    {
        int n,i,j;
        int a[][]=new int[10][10];
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the no.of nodes : ");
        n=sc.nextInt();
        System.out.println("\nEnter the cost adjacency matrix");
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]= sc.nextInt();
        floyd(a,n);
    }
}

/*
Output :
Enter the no.of nodes :
4

Enter the cost adjacency matrix
0 999 3 999
2 0 999 999
999 7 0 1
6 999 999 0

The distance matrix is

0	10	3	4

2	0	5	6

7	7	0	1

6	16	9	0


Process finished with exit code 0
 */