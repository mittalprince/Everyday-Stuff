
// Java Thread Example by extending Thread class
class multi extends Thread{

	public void run(){
		System.out.println("Thread is running.."); 	
	}

	public static void main(String args[]){
		multi t1 = new multi();
		t1.start();
	}
}


// Java Thread Example by implementing Runnable interface

class multi2 implements Runnable{
	public void run(){
		System.out.println("Thread is running...");
	}

	public static void main(String args[]){

		multi2 m1 = new multi2();
		Thread t1 = new Thread(m1);
		t1.start();
	}
}