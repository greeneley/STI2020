package phuongtien;

public class Planes extends Motobike{
	IFly plancesfly = new maybay();
	public void fly(){
		plancesfly.fly();
	}
	public Planes(int banhxe,int speed, String tenxe)
	{
		super(banhxe,speed,tenxe);
	}
}
