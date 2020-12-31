/*Given n bulbs. At first, all of them are toggled.
In the second go, every second bulb is toggled. 
In the third go, every third bulb is toggled, and so on.
Find the number of bulbs that will be ON after the process ends.
*/

import java.util.*;

public class BenjaminBulbs{
    public static void main(String args[]){
        Scanner scn = new Scanner(System.in);
        //dynamic input
        int n = scn.nextInt();
        //starting from first bulb
        int bulb = 1;
        int count = 0;
        //every bulb which is toggled odd number of times will be ON
        while (bulb * bulb <= n){
            count++;
            bulb++;
        }
        System.out.print(count);
        scn.close();
    }    
}
