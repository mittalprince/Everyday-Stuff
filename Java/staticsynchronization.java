class table{
	synchronized static void printtable(int n){
		for(int i=1; i<=10; i++){
			System.out.println(n*i);
			try{
				Thread.sleep(400);
			}
			catch(Exception e){
				System.out.println(e);
			}
		}
	}
}

class thread1 extends Thread{
	public void run(){
		table.printtable(10);
	}
}

class thread2 extends Thread{
	public void run(){
		table.printtable(100);
	}
}

class thread3 extends Thread{
	public void run(){
		table.printtable(1000);
	}
}

class thread4 extends Thread{
	public void run(){
		table.printtable(1);
	}
}

class staticsynchronization{
	public static void main(String agrs[]){
		thread1 t1 = new thread1();
		thread2 t2 = new thread2();
		thread3 t3 = new thread3();
		thread4 t4 = new thread4();

		t1.start();
		t2.start();
		t3.start();
		t4.start();
	}
}