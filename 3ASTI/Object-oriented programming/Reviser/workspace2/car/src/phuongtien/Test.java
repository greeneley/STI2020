package phuongtien;

public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		xe xemay= new xemay(2, 150,"xe may");
		xemay.banhxe();
		xemay.speed();
		xemay.tenxe();
//		xe carPolo = new xe(){};
//		carPolo = new xemay();
//		carPolo.DongCoXang();// bao loi
//		carPolo = new toto();
//		carPolo.DongCoDau();// bao loi
//		xe carPolo= new xemay(2,90,"xe may");
//		carPolo.DongCoXang();
		maybay airbus= new maybay();
		airbus.fly();
		Bird chim=new Bird();
		chim.fly();
		Motobike xemoto= new Motobike(2, 10101, "motor");
		xemoto.run();
	}

}
