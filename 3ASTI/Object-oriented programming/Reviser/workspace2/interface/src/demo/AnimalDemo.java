package demo;
public class AnimalDemo {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Drink"+ Cat.SEVENUP);
		CanEat canEat1 = new Cat("Tom");
		CanEat canEat2 = new Mouse();
		canEat1.eat();
		canEat2.eat();
		boolean isCat = canEat1 instanceof Cat;
		System.out.println("catEat1 is Cat?"+isCat);
		//ep kieu
		if(canEat2 instanceof Mouse){
			Mouse mouse = (Mouse) canEat2;
			mouse.drink();
		}
	}

}
