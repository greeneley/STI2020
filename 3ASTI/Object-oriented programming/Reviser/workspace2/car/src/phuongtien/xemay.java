package phuongtien;

public class xemay extends xe implements IRun{
	public xemay(int banhxe,int speed,String tenxe){
		super(banhxe,speed,tenxe);
	}
	public void DongCoXang(){
		System.out.println("Xe chay bang dong co xang");
	}
	public void run(){
		System.out.println("Xe nay chay toi, queo trai, queo phai");
	}
}
