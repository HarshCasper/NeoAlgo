/* Given a list of words and two words word1 and word2, find the shortest distance between those two words from the list.
 */
import java.util.*;
class Shortest_Dist {
    static List < String > arr;
    public static void main(String args[]) {
        int t = 0;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the list of words " + "\n" + "Words = ");
        arr = new ArrayList <> ();

        arr.add(sc.nextLine());
        while (sc.hasNext()) {
            arr.add(sc.nextLine());
            if (sc.hasNextInt()) {
                t = sc.nextInt();
                break;
            }

        }

        List < String > wd = new ArrayList(arr);
        while (t > 0) {
            System.out.println("Enter the words between which the shortest distance is to be calculated");
            String wd1 = sc.next();
            String wd2 = sc.next();
            System.out.println(" The shortest Distance between " + wd1 + " and " + wd2 + " is : " + shortest_dist(wd, wd1, wd2));
            //List<> wd is being allocation with elements of Collection arr
            wd = new ArrayList(arr);

            t--;
        }

    }
    public static int shortest_dist(List < String > wd, String wd1, String wd2) {
        int dist = -1;
        List < String > wdcopy = new ArrayList(wd);
        //list <> ind1. List <> ind2, for storing indexes of wd1, wd2 in List <> wd
        List < Integer > ind1 = new ArrayList <> ();
        List < Integer > ind2 = new ArrayList <> ();

        while (wd.contains(wd1)) {
            ind1.add(wd.indexOf(wd1));
            //
            wd.add(wd.indexOf(wd1), "0");
            wd.remove(wd.indexOf(wd1));

        }

        while (wdcopy.contains(wd2)) {
            ind2.add(wdcopy.indexOf(wd2));

            wdcopy.add(wdcopy.indexOf(wd2), "0");
            wdcopy.remove(wdcopy.indexOf(wd2));
        }

        for (int i = 0; i < ind1.size(); i++) {
            for (int j = 0; j < ind2.size(); j++) {
                //calculating distance between the indexes
                int d = (int) Math.abs(ind1.get(i) - ind2.get(j));
                if (dist == -1)
                    dist = d;
                else if ((dist != -1) && (d < dist))
                    dist = d;
            }
        }
        return dist;

    }
}
/*Sample Input And Output : 
 * Enter the list of words 
Words = 
practice
makes
perfect
coding
makes
2
practice
coding
 The shortest Distance between practice and coding is : 3
coding
makes
 The shortest Distance between coding and makes is : 1
 
 Timple Complexity : O(n)
 Space Complexity : O(1)
 */
