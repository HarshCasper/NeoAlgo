import java.util.*;
class Main
{  
   static int tellRow(char a[][] , char ch)
   {
       int indexI,indexJ,value=-1;
       for(indexI=0;indexI<5;indexI++)
       {
           for(indexJ=0;indexJ<5;indexJ++)
           {
               if(a[indexI][indexJ]==ch)
               value=indexI;
           }
       }
       return value;
   } 
    static int tellColumn(char a[][] , char ch)
   {
       int indexI,indexJ,value=-1;
       for(indexI=0;indexI<5;indexI++)
       {
           for(indexJ=0;indexJ<5;indexJ++)
           {
               if(a[indexI][indexJ]==ch)
                value=indexJ;
           }
       }
       return value;
   }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int indexI,indexJ,indexK,tempVarI,tempVarJ,tempVarK,tempVarL,lengthOfKeyText,lengthOfOriginalText;
        String originalText,encryptedText,tempText,keyText;
        char ch,ch1,ch2;
        char encryptionArray[][]=new char[5][5];
        System.out.println("Enter text and key");
        originalText=sc.nextLine().toLowerCase();
        keyText=sc.nextLine().toLowerCase(); 
        lengthOfOriginalText=originalText.length();
        if(lengthOfOriginalText%2!=0)
        {
            originalText=originalText+'z';
            lengthOfOriginalText++;
        } 
        lengthOfKeyText=keyText.length();
        indexJ=originalText.indexOf('j'); 
        while(indexJ!=-1)
        {
            tempText=originalText.substring(0,indexJ)+'l'+originalText.substring(indexJ+1);
            originalText=tempText;
            indexJ=originalText.indexOf('j');
            
        }indexJ=keyText.indexOf('j'); 
        indexK=0;indexI=0;indexJ=0;
       while(indexK<lengthOfKeyText)
       {   
           if(indexJ==5)
           {
               indexJ=0;
               indexI++;
           }
           if(keyText.substring(0,indexK).indexOf(keyText.charAt(indexK))==-1)
          { encryptionArray[indexI][indexJ]=keyText.charAt(indexK);
           indexJ++;
          }
          indexK++;
          }
          for(ch='a';ch<='z';ch++)
          {   if(ch=='j')
              continue;
              if(indexJ>=5)
           {
               indexJ=0;
               indexI++;
           }
           if(keyText.indexOf(ch)==-1)
           {encryptionArray[indexI][indexJ]=ch;
           indexJ++;
           }
           else continue; 
          }
        encryptedText="";
          for(indexI=0;indexI<lengthOfOriginalText;indexI=indexI+2)
          {   ch1=originalText.charAt(indexI);
              ch2=originalText.charAt(indexI+1);
              tempVarI=tellRow(encryptionArray,ch1);
              tempVarK=tellRow(encryptionArray,ch2);
              tempVarJ=tellColumn(encryptionArray,ch1);
              tempVarL=tellColumn(encryptionArray,ch2);
                 if(tempVarI==tempVarK)
                 {
                     if(tempVarJ+1==5) 
                       tempVarJ=-1;
                     if(tempVarL+1==5)
                       tempVarL=-1;
                    encryptedText=encryptedText+encryptionArray[tempVarI][tempVarJ+1]+encryptionArray[tempVarK][tempVarL+1];
                 }
                 else if(tempVarJ==tempVarL)
                 {
                      if(tempVarI+1==5) 
                       tempVarI=-1;
                     if(tempVarK+1==5)   
                       tempVarK=-1;
                    encryptedText=encryptedText+encryptionArray[tempVarI+1][tempVarJ]+encryptionArray[tempVarK+1][tempVarL];
                 }
              else 
              {
                  encryptedText=encryptedText+encryptionArray[tempVarI][tempVarL]+encryptionArray[tempVarK][tempVarJ];
              }
          }
          System.out.println(encryptedText);
    }
}

/*
Input - 
Enter text and key
Key Text: "monarchy"
Plain Text: "instruments"
Output -
Encrypted Text: gatlmzclrqtx
*/
