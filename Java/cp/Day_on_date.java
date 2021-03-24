    /*This is an code of finding day from week days just by providing date.
    for example : '03 13 2021' input will print the day on this date, that
    is 'SATURDAY'.
    */
    import java.io.*;
    import java.util.*;

    class Result 
    {
    public static String findDay(int month, int day, int year) 
    {
    /*
    The Calendar class is an abstract class that provides methods for converting
    between a specific instant in time and a set of calendar fields such as YEAR,
    MONTH, DAY_OF_MONTH, HOUR, and so on, and for manipulating the calendar
    fields, such as getting the date of the next week.
    */
        Calendar calendar = Calendar.getInstance();
        calendar.set(Calendar.MONTH, (month) - 1);
        calendar.set(Calendar.DAY_OF_MONTH, day);
        calendar.set(Calendar.YEAR, year);
        String dayOfWeek = calendar.getDisplayName(Calendar.DAY_OF_WEEK, Calendar.LONG, Locale.ENGLISH).toUpperCase();
        return dayOfWeek;
    }
    }
    public class Day_on_date 
    {
    public static void main(String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        int[] array = new int[10];
        System.out.println("Please enter the date using 'month date year' format...");
        int month = scan.nextInt();
        array[0] = month;
        int day = scan.nextInt();
        array[1] = day;
        int year = scan.nextInt();
        array[2] = year;
        String res = Result.findDay(month, day, year);
        System.out.println(res);
    }
    }
    /*
    Time complexity is O(1)
    Space complexity is O(1)

    Input :
    Please enter the date using 'month date year' format...
    03 24 2021

    Output:
    WEDNESDAY
    */
