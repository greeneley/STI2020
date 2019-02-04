package phuongtien;

public class xeoto extends xe {
	public String DongCo;
	public xeoto( int banhxe, int speed,String tenxe){
		super(banhxe,speed,tenxe);
	}
	public String DongCoDau(String DongCo){
		return this.DongCo=DongCo;
	}
//	public void SoBanhXe(){
//		System.out.println("So banh xe cua oto la: "+banhxe);
//	}
//	public void speed(){
//		System.out.println("Toc do cua oto la: "+speed);
//	}
	
	
}
