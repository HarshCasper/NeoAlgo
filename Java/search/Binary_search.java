public class Binary_search{
    //binary search algorith explanation in its readme file in wiki section
    //this can performed recursively also 
    static int binsearch(int[] a,int l,int h,int key){
        while(l<=h){
            int mid=(l+h)/2;
            if(key==a[mid])
                return mid+1;//index starts from zero so position has to be incremented by one.
            else if(key<a[mid])
                h=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }
    public static void main(String[] args){
        //to perform binary search the array must be in sorted order
        int[] a={2,5,6,7,11,13,15};
        int k=11;
        int p = binsearch(a,0,6,k);
        if(p==-1)
            System.out.println("Element Not found");
        else
            System.out.println(p);
    }
}
/*output:
5
 */
