import java.util.Scanner;

class concatenate{
	public static void  main(String args[]){

		Scanner scan = new Scanner(System.in);
		String fn = scan.nextLine();
		String ln = scan.nextLine();

		System.out.println("Your full name is "+ fn + " "+ln);
	}
}