package phuongtien;

public abstract class xe {
	public int banhxe;
	public int speed;
	public String tenxe;
	public xe(int banhxe, int speed,String tenxe){
		this.banhxe=banhxe;
		this.speed=speed;
		this.tenxe=tenxe;
	}
	public void thongtin(){
		System.out.println("Ten Xe la: "+tenxe);
		System.out.println("Toc Do: "+speed);
		System.out.println("so banh xe la "+banhxe);
	}
	public void banhxe(){
		System.out.println("so banh xe la "+banhxe);
	}
	public void speed(){
		System.out.println("Toc Do: "+speed);
	}
	public void tenxe(){
		System.out.println("Ten Xe la: "+tenxe);
	}
}
