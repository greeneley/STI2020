package filtre_de_boom;

import java.security.MessageDigest;

public class MD5Test {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		String original = "Brasil";
		MessageDigest md = MessageDigest.getInstance("MD5"); 
		md.update(original.getBytes());
		byte[] digest = md.digest();
		StringBuffer sb = new StringBuffer();
		for (byte b : digest) {
			sb.append(String.format("%02x", b & 0xff ));
		}
		System.out.println("original:" + original);
		System.out.println("digested(hex):"+ sb.toString());
		System.out.println("premier element du digest:"+digest[0]);
	}

}