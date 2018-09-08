class example{
	public static void main(String args[]){
		int arr[] = {1,2,3,4,5};

		for(int i=0; i<= arr.length ; i++){
			Exception E = new Exception();

			
			try{
					System.out.println(arr[i]);
			}

			catch(Exception e){
				System.out.println("Error: Out of bound access");
			}
		}
	}
}