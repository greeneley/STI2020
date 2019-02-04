package TestObject;

public class TestObject {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/* kiem tra xem cach luu biến vào địa chỉ bộ nhớ như thế nào
		 * xem thử copi 1 đối tượng như thế nào
		 */
//		Object o1 =new Object();
//		Object o2 =new Object();
//		Object o3 =o1;
//		System.out.println(o1);
//		System.out.println(o2);
//		System.out.println(o3);
//		if(o1==o2)
//			System.out.println("Meme chose");
//		else
//			System.out.println("Difference");
//		Pair p1=new Pair(10,15);
//		System.out.println(p1);
//		Pair p2=new Pair(10, 15);
//		System.out.println(p2);
//
//		if(p1==p2) // so sanh dia chi xem co trung nhau ko
//			System.out.println("Meme chose");
//		else
//			System.out.println("Difference"); 
//		//ket qua khac nhau => dia chi luu tru khac nhau 
//		//Est-ce qu'ils sont egaux (nuance subtile qvec le precedent)
//		if(p1.equals(p2))
//			System.out.println("Meme chose");
//		else
//			System.out.println("Difference");  // van diffence 
//		// tien hanh override no trong ham pair, va thu lai t thay giong nhau 
		//===================================================
		//GenericPaire<int, int> pii= new GenericPaire<int,int>(10,15) ; //loi vi ta ko the truyen du lieu vao 
																	// bang cach viet int dc, thay bang integer
		GenericPaire<Integer, Integer> pii = new GenericPaire<Integer, Integer>(10, 15);
		System.out.println(pii);
		Pair p1=new Pair(10,15);
		//test p1 = pii ?
		if(p1.equals(pii))
			System.out.println("Meme chose");
		else
			System.out.println("Difference"); // diffence 
		//override ham equal tuong tu xem thu
		
	}

}
