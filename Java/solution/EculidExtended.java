package dataStructure;

import java.util.Scanner;

public class EculidExtended {
	
	private static int  gcdCal(int num1,int num2) {
		int s1,s2,s,t1,t2,t,q,r1,r2,r;
		s1=1;
		s2=0;
		t1=0;
		t2=1;
		if(num1>num2) {
			r1=num1;
			r2=num2;
		}
		else {
			r1=num2;
			r2=num1;
		}
		
		while(r2>0) {
		q=r1/r2;
		r=r1%r2;
		s=s1-s2*q;
		t=t1-t2*q;
		
		r1=r2;
		r2=r;
		s1=s2;
		s2=s;
		t1=t2;
		t2=t;
		
		}
		
		return r1;
		
		
		
		
		
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int num1=sc.nextInt();
		int num2=sc.nextInt();
		
		int result=gcdCal(num1,num2);
		System.out.println(result);
		sc.close();
	}
	

}
