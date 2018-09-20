// class test{

// 	public static void main(String args[]){

// 		System.out.println("Hello main!");
		
// 	}

// 	static{
// 		System.out.println("Hello static!"); // static will execute before calling of main()
// 	}

// }

//  -------------------------

// class test{
// 	public static void main(String args[]){
// 		int num1, num2;
// 		float num4;
// 		num1 = Integer.parseInt(args[0]);
// 		num2 = Integer.parseInt(args[1]);

// 		num4 = (num1+num2)/2;
// 		System.out.println(num4);
// 	}
// }

// ---------------------------

// class Test { 
//     static int i; 
//     int j; 
      
//     // start of static block  
//     static { 
//         i = 10; 
//         System.out.println("static block called "); 
//     } 
//     // end of static block  
// } 
  
// class Main { 
//     public static void main(String args[]) { 
  
//         // Although we don't have an object of Test, static block is  
//         // called because i is being accessed in following statement. 
//         System.out.println(Test.i);  
//     } 
// } 

// -----------------------------

class GFG  
{ 
    public static void main (String[] args)  
    {          
      // declares an Array of integers. 
      int[] arr = new int[]{1,2,3,4,5};
          
      // allocating memory for 5 integers. 
      //arr = new int[5]; 
          
      // initialize the first elements of the array 
      //arr[0] = 10; 
          
      // initialize the second elements of the array 
      //arr[1] = 20; 
          
      //so on... 
      // arr[2] = 30; 
      // arr[3] = 40; 
      // arr[4] = 50; 
          
      // accessing the elements of the specified array 
      for (int i = 0; i < arr.length; i++) 
         System.out.println("Element at index " + i +  
                                      " : "+ arr[i]);           
    } 
} 