import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int i,j,k,l,m,n,h,mid1,mid2,f=-1,element;
        System.out.println("Enter length of array");
        n=sc.nextInt();
        System.out.println("Enter  array elements");
        int arr[]=new int[n];
        for(i=0;i<n;i++)
        arr[i]=sc.nextInt();
         System.out.println("Enter element to be searched");
        element=sc.nextInt();
        
        Arrays.sort(arr);
        l=0;h=n-1;
        while(l<=h)
        {
           mid1 = l + (h-l)/3;
           mid2 = h - (h-l)/3;
           if(element == arr[mid1])
         {
             f = mid1+1;break;
         }
           else if(element == arr[mid2])
          {
              f=mid2+1;break;
          }
           else if(element < arr[mid1])
           h=mid1-1;
           else if(element < arr[mid2] && element > arr[mid1])
          {
              l=mid1+1;
              h=mid2-1;
          }
           else 
           l=mid2+1;
        }
        if(f!=-1)
        System.out.println("Element found at "+(f));
        else
        System.out.println("Element not found");
    }
}
