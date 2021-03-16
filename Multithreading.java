public class Multithreading 
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Thread3 th1 = new Thread3();
		Thread4 th2 = new Thread4();
		th1.start();
		th2.start();
		
		
	}
	

}

class Thread3 extends Thread
{
	
	public void run()
	{
		for(int i=0;i<3;i++)
		{
		System.out.println("Hello from thread1");
		}
	}
}
class Thread4 extends Thread
{
	public void run()
	{
		for(int i=0;i<3;i++)
		{
		System.out.println("Hello from thread2");
		}
	}
}
//OUTPUT  -- 
//Hello from thread1
//Hello from thread2
//Hello from thread2
//Hello from thread2
//Hello from thread1
//Hello from thread1

