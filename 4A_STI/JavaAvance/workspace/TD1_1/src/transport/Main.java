package transport;

import java.util.Vector;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Camion c1 = new Camion("Renault");
		Camion c2 = new Camion("Toyata");
		Camion c3 = new Camion("Vinmart");
		//Creer nouveau vector
		Vector<Camion> car = new Vector<Camion>();
		car.addElement(c1);
		car.addElement(c2);
		car.addElement(c3);
		
		for(int i = 0; i< 123456; i++) {
			car.add(new Camion("toto"));
		}
		System.out.println("Marque:" + c1.toString());
		System.out.println("Marque:" + c2.toString());
		System.out.println("Marque:" + c3.toString());
		
		System.out.println("Used Memory   :  " + (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) + " bytes");
        System.out.println("Free Memory   : " + Runtime.getRuntime().freeMemory() + " bytes");
        System.out.println("Total Memory  : " + Runtime.getRuntime().totalMemory() + " bytes");
        
        System.out.println("Max Memory  : "+java.lang.Runtime.getRuntime().maxMemory()+ " bytes");
	}

	
}
