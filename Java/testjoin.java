class testjoin extends Thread{
	public void run(){
		for(int i=1; i<5; i++){
			try{
				Thread.sleep(500);
			}
			catch(InterruptedException e){
				System.out.println(e);
			}
			System.out.println(i);
		}
	}

	public static void main(String agrs[]){
		testjoin t1 = new testjoin();
		testjoin t2 = new testjoin();
		testjoin t3 = new testjoin();

		t1.start();
		try{
			t1.join(1500);
		}
		catch(Exception e){
			System.out.println(e);
		}

		t2.start();
		t3.start();
	}
}