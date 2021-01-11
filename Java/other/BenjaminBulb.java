/* Problem Description:
If we have n number of bulbs and all are toggled n times.
When it is toggled for the first time, all bulbs are toggled, when they are toggled for the 
second time, every second bulb is toggled, and the third time every 3rd bulb is toggled and so on.
Find the number of bulbs that will be toggled ON after n toggles.*/

import java.util.*;
class BenjaminBulb {
    public static int bulbSwitch(int bulb_n) {
        int bulb_i = 1;
        int count = 0;

        //perform check for all n bulbs starting 
        //from bulb_i i.e. bulb_1 upto bulb_n
        while(bulb_i * bulb_i <= bulb_n) {
            count++;
            bulb_i++;
        }
        return count;
    }    
    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        int bulb_n = scn.nextInt();
        int result = bulbSwitch(bulb_n);
        System.out.println(result);
        scn.close();
    }
}

