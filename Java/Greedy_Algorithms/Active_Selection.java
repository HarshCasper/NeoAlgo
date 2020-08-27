//Given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
//
//        Note : The start time and end time of two activities may coincide.
//
//        Input:
//        The first line contains T denoting the number of testcases. Then follows description of testcases. First line is N number of activities then second line contains N numbers which are starting time of activies.Third line contains N finishing time of activities.
//
//        Output:
//        For each test case, output a single number denoting maximum activites which can be performed in new line.
//
//        Constraints:
//        1<=T<=50
//        1<=N<=1000
//        1<=A[i]<=100
//
//        Example:
//        Input:
//        2
//        6
//        1 3 2 5 8 5
//        2 4 6 7 9 9
//        4
//        1 3 2 5
//        2 4 3 6
//
//        Output:
//        4
//        4
//
//        Explanation:
//        Test Case 1: The following activities can be performed (in the same order):
//        (1, 2)
//        (3, 4)
//        (5, 7)
//        (8, 9)



import java.util. * ;
import java.lang. * ;
import java.io. * ;

class Main {
  public static void main(String[] args) {
    //code

    Scanner s = new Scanner(System. in );
    int t = s.nextInt();
    while (t-->0) {
      int n = s.nextInt();
      int[] start = new int[n];
      int[] finish = new int[n];

      for (int i = 0; i < n; i++) {
        start[i] = s.nextInt();

      }
      for (int i = 0; i < n; i++) {
        finish[i] = s.nextInt();

      }
      for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
          if (finish[j] > finish[j + 1]) {
            int temp = finish[j];
            finish[j] = finish[j + 1];
            finish[j + 1] = temp;

            int te = start[j];
            start[j] = start[j + 1];
            start[j + 1] = te;
          }

        }

      }

      int i = 0;
      int c = 1;
      for (int j = 1; j < n; j++) {
        if (finish[i] <= start[j]) {
          c++;
          i = j;
        }

      }
      System.out.println(c);

    }

  }
}

