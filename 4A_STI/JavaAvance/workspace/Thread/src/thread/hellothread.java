package thread;

public class hellothread extends Thread {

	private String Name;
	private Integer n;
	private Object r1;
	private Object r2;

	public hellothread(String Name, Integer n, Object r1, Object r2) {
		super();
		this.Name = Name;
		this.n = n;
		this.r1 = r1;
		this.r2 = r2;
	}

	public void run() {
		for(Integer i=0;i<20;i++) {
			System.out.println(" [ " + this.Name + "]");
			try {
				Thread.sleep(this.n);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		System.out.println("=> Thread " + this.Name + " Stopped");
		// Exo 5 et Exo 6
		for(Integer i=0; i<200; i++) {
			synchronized (this.r1) {
//				try {
//					Thread.sleep(3000);
//				} catch (InterruptedException e) {
//					// TODO Auto-generated catch block
//					e.printStackTrace();
//				}
				synchronized (this.r2) {
					System.out.println("Je suis "+this.Name+" et j’a i les deux ressources ! ");
				}
		  }
		}
	}
}
