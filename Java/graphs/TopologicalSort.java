import java.util.*;
class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    while(t-->0){
    int ver = sc.nextInt();
    int edg = sc.nextInt();
    ArrayList<ArrayList<Integer>> list = new ArrayList<>();
    for(int i=0;i<=ver;i++) list.add(i,new ArrayList<Integer>());
    System.out.println(list);
    for(int i=1;i<edg;i++){
      int v1 = sc.nextInt();
      int v2 = sc.nextInt();
      list.get(v1).add(v2);
    }
    sc.close();
    System.out.println(list);
    int[] array = new int[ver+1];
    array = new TopologicalSort().toposort(list,ver);
    boolean valid = new TopologicalSort().checkToposort(list,ver,array);
    if (valid)
    System.out.println("Yes the TopologicalSort is correct");
    else{
      System.out.println("No  the TopologicalSort is incorrect");
    }
    }
  }
}
class TopologicalSort{
  public int[] toposort(ArrayList<ArrayList<Integer>> list,int ver){
    int[] count = new int[ver+1];
    new Helper().reInitialize(count);
    for(int i=0;i<list.size();i++){
      ArrayList<Integer> temp = new ArrayList<>();
      temp = list.get(i);
      for(int j=0;j<temp.size();j++){
        count[temp.get(j)]++;
      }
    } 
    Queue<Integer> queue = new LinkedList<>();
    for(int i=0;i<count.length;i++){
      if (count[i]==0){
        queue.add(i);
      }
    }
    System.out.println(queue);
    int[] array = new int[ver+1];
    int index=0;
    while(queue.size()!=0){
      int src = queue.poll();
      array[index]= src;
      index++;
      ArrayList<Integer> parti = new ArrayList<>();
      parti = list.get(src);
      for(int i=0;i<parti.size();i++){
        count[parti.get(i)]-=1;
        if(count[parti.get(i)]==0){
          queue.add(parti.get(i));
        }
      }
    }
    new Helper().print(array);
    return array;
  }
  public boolean checkToposort(ArrayList<ArrayList<Integer>> list,int ver,int[] array){
    boolean initially = true;
      for(int i=0;i<ver;i++){
        int n = list.get(array[i]).size();
        for(int j=0;j<list.get(array[i]).size();j++){
          for(int k=i+1;k<=ver;k++){
            if(array[k]==list.get(array[i]).get(j)){
              n--;
            }
          }
        }
        if(n!=0){
          initially=false;
          break;
        }
        if(initially==false) break;
      }
      return initially;
  }
}
class Helper{
  public void reInitialize(int[] count){
    for(int i=0;i<count.length;i++) count[i]=0;
  }
  public void print(int[] array){
    for(int i: array) System.out.print(i+" ");
  }
}
