class Bicyle{

	public int gear;
	public int speed;

	public Bicyle(){
		System.out.println("Hello world");
	}

	public Bicyle(int x){
		System.out.println("hello Mr. "+ x);
	}
}

class constructor{
	public static void main(String agrs[]){
		// make two obj of Bicyle and overload the constructor using this (first call default while second call parameterise)
		Bicyle obj1 = new Bicyle();
		Bicyle obj2 = new Bicyle(10);
	}
}