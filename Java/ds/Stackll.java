//Stack implemetation Its readme file in wiki
import java.util.*;
import java.lang.*;
class mystack<E>
{
    static class Node<E> {
        E data;
        Node<E> next;
        Node(E data) {
            this.data = data;
            next = null;
        }
    }
    Node<E> head;
    Node<E> top;
    int c=0;
    boolean isempty(){ return head==null;}
    void push(E a){
        Node<E> temp=new Node<E>(a);
        Node<E> temp1=head;
        if(isempty()){
            head=temp;
            top=head;
            c++;
            return;
        }
        else{
            while(temp1.next!=null){
                temp1=temp1.next;
            }
            temp1.next=temp;
            c++;
            top=temp;
        }
    }
    E peep(){
        if(isempty())
            return null;
        return top.data;
    }
    E pop() throws Exception{
        if(isempty()){
            throw  new Exception("eeempty");
        }
        else if(head==top){
            Node<E> temp1=head;
            head=top=null;
            return temp1.data;
        }
        else{
            Node<E> temp1=head;
            Node<E> temp;
            while(temp1.next.next!=null){
                temp1=temp1.next;
            }
            temp=temp1.next;
            temp1.next=null;
            top=temp1;
            c--;
            return temp.data;
        }
    }
}

public class Stackll {
    public static void main(String[] args) throws Exception {
        mystack<Integer> s = new mystack<Integer>();
        s.push(1);
        s.push(2);
        s.push(3);
        System.out.println(s.peep());
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.peep());
        System.out.println(s.pop());
    }
}
/*
output:
3
3
2
1
null
Exception in thread "main" java.lang.Exception: eeempty
	at mystack.pop(Stackll.java:43)
	at Stackll.main(Stackll.java:76)
 */
