package thread;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Ressource r1 = new Ressource();
		Ressource r2 = new Ressource();
		hellothread thread_1 = new hellothread("Object 1", 5, r1, r2);
		hellothread thread_2 = new hellothread("Object 2", 8, r2, r1);
		thread_1.start();
//		try {
//			Thread.sleep(3000);
//		} catch (InterruptedException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
		thread_2.start();
	}

}
