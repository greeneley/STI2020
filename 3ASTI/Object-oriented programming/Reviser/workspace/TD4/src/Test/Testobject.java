package Test;

public class Testobject {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Object o1 = new Object();
//		Object o2 = new Object();
		System.out.println(o1);
		Object o3 = o1; 
		System.out.println(o3);
		/*
		 * compare address of p1 and p2
		 */
		Paire p1 = new Paire(10,15);
		System.out.println(p1);
		Paire p2 = new Paire(10,15);
		System.out.println(p2);
		if(p1==p2){
			System.out.println("True");
		}
		else System.out.println("False");
		if(p1.equals(p2))
			System.out.println("Egale");
		else
			System.out.println("Not");
		/*
		 * ================================
		 */
		GenericPaire<Integer, Integer> pii = new GenericPaire<Integer, Integer>(10, 15);
		System.out.println(pii);
		if(p1.equals(pii))
			System.out.println("True");
	}

}
