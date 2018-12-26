import java.util.ArrayList;

class wrapper{
	public static void main(String agrs[]){

		int b = 10;
		Integer intobj = new Integer(b);

		System.out.println("Integer Object Value "+ b);

		int iv = intobj;

		System.out.println("Int Value "+iv);

		// char ch = 'a';

		// Character Ch = ch; // autoboxing 

		// System.out.println(Ch);

		// ArrayList<Integer> arrayList = new ArrayList<Integer>();
		// arrayList.add(25); // autoboxing as 25 in int not Integer

		// System.out.println(arrayList.get(0));

		// char a = Ch; // unboxing
		// int num = arrayList.get(0); //unboxing

		// System.out.println(a+" "+num);  
	}
}