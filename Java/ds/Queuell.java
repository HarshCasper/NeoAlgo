//Queue implemetation Its readme file in wiki
import java.util.*;
import java.lang.*;
class myq<E> {
    static class Node<E>{
        E data;
        Node<E> next;
        Node(E a){
            this.data=a;
            next=null;
        }
    }
    Node<E> front;
    Node<E> rear;
    int c=0;
    boolean isempty(){
        return front==null;
    }
    void add(E a){
        Node<E> temp=new Node<E>(a);
        if(isempty()){
            front=temp;
            rear=temp;
            c++;
            return;
        }
        else{
            rear.next=temp;
            rear=temp;
            c++;
            return;
        }
    }
    E remove() throws Exception{
        Node<E> t;
        if (isempty()){
            throw new Exception("EEEEEmpty");
        }
        else if(c==1){
            t=front;
            front=null;
            rear=null;
            c--;
        }
        else{
            t=front;
            front=front.next;
            c--;
        }
        return t.data;
    }
    E Front(){
        if (isempty()){
            return null;
        }
        else{
            return front.data;
        }
    }
    E Rear(){
        if (isempty()){
            return null;
        }
        else{
            return rear.data;
        }
    }
}
public class Queuell {
    public static void main(String[] args) throws  Exception{
        myq<Integer> qe = new myq<Integer>();
        qe.add(10);
        qe.add(20);
        qe.add(30);
        qe.add(40);
        System.out.println(qe.Front());
        System.out.println(qe.Rear());
        System.out.println(qe.remove());
        System.out.println(qe.remove());
        System.out.println(qe.Front());
        System.out.println(qe.remove());
        System.out.println(qe.remove());
        System.out.println(qe.remove());

    }
}
/*
output:
10
40
10
20
30
30
40
Exception in thread "main" java.lang.Exception: EEEEEmpty
	at myq.remove(Queuell.java:37)
	at Queuell.main(Queuell.java:83)
 */