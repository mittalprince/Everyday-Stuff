class variableType{
	public int num1;	// instance variable
	public int num2;
	public static String s; // static variable (val preserve through the program)

	public variableType(int num1, int num2){
		this.num1 = num1; 
		this.num2 = num2;
	}

	public void add2(int num1, int num2){
		int add = this.num1+this.num2; // use num1 val of instace variable (use this to refer instace variable)
		System.out.println(add);
	}

	public void add1(int num1, int num2){
		int add = num1+num2; // use num1 val of paramter
		System.out.println(add);
	}
}

public class variables{
	public static void main(String args[]){
		variableType obj1 = new variableType(10,20);
		obj1.add2(1,2);
		obj1.add1(1,2);
	}
}

