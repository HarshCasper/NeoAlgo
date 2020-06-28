public class Linear_search{
static int linsearch(int[] a,int k){
for(int i=0;i<a.length;i++){
if(a[i]==k)
return i+1;//returns position
}
return -1;//returns -1 if not found
}
public static void main(String[] args){
int[] a={2,7,8,9,1,5,3,4};
int key=8;
System.out.println(linsearch(a,key));
}
}