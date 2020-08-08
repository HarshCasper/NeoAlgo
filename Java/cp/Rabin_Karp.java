/*
Rabin–Karp algorithm or Karp–Rabin algorithm is a string-searching algorithm that uses hashing to find an exact match of a pattern string in a text. 
It uses a rolling hash to quickly filter out positions of the text that cannot match the pattern, and then checks for a match at the remaining positions.
*/
import java.util.*;
class  Main
{
    public static void main( String[] args )
 {
   String actualText , patternToBeSearched;
   Scanner sc=new Scanner(System.in);
   System.out.println( "Enter actual text" ) ;
   actualText = sc.nextLine();
   System.out.println( "Enter pattern to be searched" );
   patternToBeSearched = sc.nextLine();
   int indexI , indexJ , locationIndex = -1 , count = 0;
   long sumOfCharactersOfTempString = 0 ,sumOfCharactersOfPatternToBeSearched = 0;
   for( indexI = 0; indexI < patternToBeSearched.length() ; indexI++ )
   {
       sumOfCharactersOfPatternToBeSearched = sumOfCharactersOfPatternToBeSearched + (long) (patternToBeSearched.charAt(indexI) * Math.pow(127,patternToBeSearched.length()-1-indexI) );
   }
   for( indexI = 0; indexI <= actualText.length() - patternToBeSearched.length(); indexI++ )
   {
       sumOfCharactersOfTempString = 0; indexJ = indexI;
       for( count = 0; count < patternToBeSearched.length(); count++ )
        {   
            sumOfCharactersOfTempString = sumOfCharactersOfTempString + (long)( actualText.charAt(indexJ) * Math.pow(127,patternToBeSearched.length()-1-count) );
            indexJ++;
        }
        if( sumOfCharactersOfTempString == sumOfCharactersOfPatternToBeSearched)
        locationIndex = indexI;
         
    }
    if(locationIndex != -1)
    System.out.println( "Pattern found at index " + locationIndex );
    else
    System.out.println( "Pattern not found" );
    }
}
