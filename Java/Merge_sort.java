public class Merge_sort {
//merge sort function to recursively break the array to one-one element
    static void merge_sort(int[] a,int l,int h){
        int mid;
        if(l<h){
            mid=(l+h)/2;
            merge_sort(a,l,mid);
            merge_sort(a,mid+1,h);
            merge(a,l,mid,h);
        }
    }
//merge function to compare and merge to elements 
    static void merge(int[] a,int l,int mid,int h){
        int i=l,j=mid+1,k=l;
        int[] b=new int[100];
        while(i<=mid && j<=h){
            if(a[i]<a[j])
                b[k++]=a[i++];
            else
                b[k++]=a[j++];
        }
        for(;i<=mid;i++)
            b[k++]=a[i];
        for(;j<=h;j++)
            b[k++]=a[j];
        for(i=l;i<=h;i++)
            a[i]=b[i];
    }
    public static void main(String[] args){
        int[] a={11, 13,7,12,16,9,24,5,10,3};
        merge_sort(a,0,9);
        for(int i=0;i<10;i++)
            System.out.print(a[i]+" ");
    }
}
/*output:
3 5 7 9 10 11 12 13 16 24 
*/