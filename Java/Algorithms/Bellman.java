/* 8. Write a program to find the shortest path between vertices using Bellman ford algorithm.
   
 */
import java.util.Scanner;

public class Bellman {
    private int num_ver;
    private int[] d;

    public static final int max_val = 999;

    public Bellman(int num_ver) {
        this.num_ver = num_ver;
        d = new int[num_ver + 1];
    }

    public void bellmanFord(int source, int[][] a) {
        for(int node=1; node<=num_ver; node++) {
            d[node] = max_val;
        }

        d[source] = 0;

        for(int node=1; node<=num_ver-1; node++) {
            for(int sn=1; sn<=num_ver; sn++) {
                for(int dn=1; dn<=num_ver; dn++) {
                    if(a[sn][dn] != max_val) {
                        if(d[dn] > d[sn] + a[sn][dn]) {
                            d[dn] = d[sn] + a[sn][dn];
                        }
                    }
                }
            }
        }

        for(int sn=1; sn<=num_ver; sn++) {
            for(int dn=1; dn<=num_ver; dn++) {
                if(a[sn][dn] != max_val) {
                    if(d[dn] > d[sn] + a[sn][dn]) {
                        System.out.println("\nGraph contains negative edge cycle.\n");
                    }
                }
            }
        }

        for(int vertex=1; vertex<=num_ver; vertex++) {
            System.out.println("Distance of source " + source + " to vertex " + vertex + " is: " + d[vertex]);
        }
    }

    public static void main(String[] args) {
        int source;
        int num_ver;
        int[][] a;

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter no. of vertices:");
        num_ver = sc.nextInt();

        a = new int[num_ver + 1][num_ver + 1];

        System.out.println("Enter adjacency matrix:");
        for(int sn=1; sn<=num_ver; sn++)
            for(int dn=1; dn<=num_ver; dn++)
                a[sn][dn] = sc.nextInt();

        System.out.println("Enter source vertex:");
        source = sc.nextInt();

        Bellman b = new Bellman(num_ver);
        b.bellmanFord(source, a);
        sc.close();
    }
}
