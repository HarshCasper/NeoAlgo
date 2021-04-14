/*
 - Meetings :
      We will give the input as our available time and if our available time is in between
      meeting_hour1 to meeting_hour2 then we are able to attend the meeting otherwise not
      time is a string in the format "HH:MM AM" or "HH:MM PM" (without quotes)

 - Example : Let the available time be 01:04 AM and scheduled meeting time be 12:00 AM to 03:00 PM
             now, 01:04 AM lies between 12:00 AM to 03:00 PM hence, we can attend the meeting

 - Approach :
   1. As the time is in the form of String so we have to convert it to the integer and we will use
      time conversion method

   2. If time is in AM then just multiply hour by 100 and add minutes to it
      for example - time is 01:04 AM
                    multiply hour by 100(1*100 = 100) and then add minutes(100 + 04 = 104)

   3. If time is in PM then multiply hour by 100 and add 1200 + minutes to it
      for example - time is 01:04 PM
                    multiply hour by 100(1*100 = 100) and then add 1200 + minutes(100 + 1200 + 04 = 1304)

   4. After converting String to integer check the condition (available_time >= meeting_hour1 && available_time <= meeting_hour2)
      if it is true then you can attend the meeting otherwise not
 */

import java.util.Scanner;

public class Meetings {

	//method to convert String to an integer
	public static int timeConversion(String s) {

        //taking first 2 characters of String
		int hour = Integer.parseInt(s.substring(0, 2)) % 12;
		hour = hour*100;

        //If String ends with PM then add 1200 to hour
		if (s.endsWith("PM")) {
			hour += 1200;
		}
		//adding minutes to hour
		int minute = Integer.parseInt(s.substring(3, 5));
		hour = hour + minute;

		return hour;
	}

	//main method
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		//Enter the time when you are available
		System.out.print("Enter Time : ");
		String date1=sc.nextLine();

		int available_time = Meetings.timeConversion(date1);

		//Enter your scheduled meeting time
		System.out.print("Enter the Meeting Time : ");
		String p = sc.nextLine();

		String time = p.substring(0, 8);
		int meeting_hour1 = Meetings.timeConversion(time);
		String time2 = p.substring(9, 17);
		int meeting_hour2 = Meetings.timeConversion(time2);

		String result ;
		//Checking condition (meeting_hour1 <= available_time <= meeting_hour2)
		if(available_time >= meeting_hour1 && available_time <= meeting_hour2) {
			result = "Yes, you can attend the meeting";
		}else {
			result = "No, you can not attend the meeting";
		}
		//Printing Result
		System.out.println(result);
	}
}
/*
 - Test Cases :
    1. Input : Enter Time : 12:01 AM
               Enter the Meeting Time : 12:00 AM 03:00 PM
      Output : Yes, you can attend the meeting

- Complexity Analysis :
  * Time Complexity : O(1)
   	     this program runs at constant time

  * Space Complexity : O(1)
	  	 Auxiliary space : O(1)  +  input space : O(1)
 */
   
