import java.util.*;

public class CountInversion{
    private static int mergeSort(int[] arr, int low, int high){
        int count = 0;
        if(low < high){
            int mid = low + (high-low)/2;
            count += mergeSort(arr, low, mid-1);
            count += mergeSort(arr, mid+1, high);

            count+= merge(arr, low, high,mid);
            
        }
        return count;
    }
    private static int merge(int[] arr, int low, int high, int mid){
        int cnt = 0;
        int i = low;
        int j = mid+1;

        while(i<=mid && j <=high){
            if(arr[i] <= arr[j]){
                i++;
                
            }
            else{
                j++;
                cnt += high-i;  
            }
        }
       
        return cnt;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        int[] arr = new int[len];
        for(int i = 0; i < len; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(mergeSort(arr,0,len-1));
    }
    
    
    
}
