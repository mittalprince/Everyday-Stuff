class largest{
	public static void main(String args[]){
		int arr[] = {1,2,3,4,5};
		int max = arr[0];
		for(int i=1; i<5; i++){
			if(max < arr[i])
				max = arr[i];
		}

		System.out.println("Maximum Value is: "+max);
	}
}