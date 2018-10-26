class table{

	void printtable(int n){
		synchronized(this){
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
}

class synchronisedblock{

	public static void main(String args[]){
		final table obj = new table();
		Thread t1 = new Thread(){
			public void run(){
				obj.printtable(5);
			}
		};
		Thread t2 = new Thread(){
			public void run(){
				obj.printtable(100);
			}
		};

		t1.start();
		t2.start();
	}
}