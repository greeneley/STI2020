package Solution;

public class test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("thanhhai 123");
		equation p1= new equation(0, 2);
		System.out.println("gia tri a: "+p1.a);
		System.out.println("gia tri b: "+p1.b);
		System.out.println("phuong trinh: "+p1.a+"*x+ "+p1.b+"=0");
		System.out.println(p1.solve());
	}

}
