/*
  Segmented sieve is used to print prime number in a given range(l,r).
*/

import java.util.ArrayList;
import java.util.Scanner;

public class Segmented_Sieve {

	public static int MAX=1000000;
	public static boolean prime[]=new boolean[MAX+1];
	
//	Basic sieve returning a list of primes number less than or equal to MAX
	public static ArrayList<Integer> sieve() {
		
//		Marking all number as true initailly
		for(int i=0;i<=MAX;i++) {
			prime[i]=true;
		}
		
//	0 and 1 are not prime , so marking them as false		
		prime[0]=prime[1]=false;
		
		for(int i=2;i*i<=MAX;i++) {
//			If the given number is prime
			if(prime[i]==true) {
//				Marking all its multiple as false
				for(int j=i*i;j<=MAX;j+=i) {
					prime[j]=false;
				}
			}
		}
		
		ArrayList<Integer> primeList=new ArrayList<Integer>();
		
		for(int i=0;i<=MAX;i++){
			if(prime[i]==true) {
				primeList.add(i);
			}
		}
		
		return primeList;
	}
	
//	Printing prime number in the given range l to r
	public static void printPrimeInRange(long l,long r,ArrayList<Integer> primeList) {
		
		boolean array[]=new boolean[(int)(r-l+1)];
		
		for(int i=0;i<=(r-l);i++) {
			array[i]=true;
		}
		
		for(int i=0;i<primeList.size()&&(long)primeList.get(i)*primeList.get(i)<=r;i++) {
			
			int currentPrime=primeList.get(i);
			
//			Finding nearest number greater than or equal to l  which is divisible by currentPrimeNumber
			int baseValue=(int)(l/currentPrime)*currentPrime;
			
			if(baseValue<l) {
				baseValue+=currentPrime;
			}
			
			for(int j=baseValue;j<=r;j+=currentPrime) {
				array[(int)(j-l)]=false;
			}
			if(baseValue==currentPrime) {
				array[(int)(baseValue-l)]=true;
			}
		}
		
		for(int i=0;i<=(r-l);i++) {
			if(array[i]==true) {
				System.out.print((i+l)+" ");
			}
		}
	}
	
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		
		System.out.println("Enter lower limit : ");
		long l=sc.nextLong();
		
		System.out.println("Enter upper limit  :");
		long r=sc.nextLong();
		
		ArrayList<Integer> primeList=sieve();
		
		System.out.println("Prime Number in range " + l + " to "+ r +" are : ");
		printPrimeInRange(l, r, primeList);
		
		
		
	}

}
