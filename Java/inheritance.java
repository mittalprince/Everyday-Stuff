class Bicycle{

	public int gear;
	public int speed;

	public Bicycle(int gear, int speed){

		this.gear = gear; // use this to point gear varibale of class Bicycle as constructor parameter of same name
		this.speed = speed ;
	}

	public void applyBrake(int dec){

		speed-=dec;
	}

	public void speedUp(int inc){

		speed+=inc;
	}

	// Object class contains toString() method. We can use toString() method to get string representation of an object
	// It is highly recommended to override toString() method in our class also.
	public String toString(){

		return ("Gear is: "+gear+"\nSpeed is: "+ speed);
	}
}

class B extends Bicycle{

	public int seatHeight;

	public B(int gear, int speed, int seatHeight){

		//invoke base-class constructor (Bicycle)
		super(gear, speed);
		this.seatHeight = seatHeight;

	}

	public void seatHeight(int value){
		seatHeight = value;
	}

	//overriding toString() method of Bicycle to print more info
	public String toString(){

		return (super.toString()+"\nseatHeight is: "+seatHeight);
	}
}

class test{

	public static void main(String args[]){

		B obj1 = new B(3,100,25);
		System.out.println(obj1.toString());
	}
}