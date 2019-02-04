package phuongtien;

public class Motobike extends xe{
	IRun bird = new Bird(); 
	public void run(){
		bird.run();
	}
	public Motobike(int banhxe, int Speed, String tenxe){
		super(banhxe,Speed,tenxe);
	}
}
