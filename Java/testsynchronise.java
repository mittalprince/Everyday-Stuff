class table{

	synchronized void printtable(int n){
		for(int i=1; i<=5; i++){
			System.out.println(n*i);
			try{
				Thread.sleep(500);
			}
			catch(Exception e){
				System.out.println(e);
			}
		}
	}
}

class thread1 extends Thread{
	table t;
	thread1(table t){
		this.t = t;
	}

	public void run(){
		t.printtable(5);
	}
}

class thread2 extends Thread{
	table t;
	thread2(table t){
		this.t = t;
	}

	public void run(){
		t.printtable(100);
	}
}

class testsynchronise{

	public static void main(String args[]){
		table obj = new table();
		thread1 t1 = new thread1(obj);
		thread2 t2 = new thread2(obj);

		t1.start();
		t2.start();
	}
}