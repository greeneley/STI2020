package TD2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		int[][] a = {{0,1,1,1},{1,2,1,2},{0,1,2,3},{0,3,3,4},{1,2,3,5},{1,4,2,6},{0,2,4,7},{0,4,5,8},{1,5,4,9},{0,5,5,10}};
//		System.out.println(a[0]);
//		int[][] a = {{0,1,1,1},{1,2,1,2}};
//		System.out.println(a[1][1]);
//		Scanner input = new Scanner(System.in);	
//    	System.out.print("Combien de ressources: ");
//    	int ressource = input.nextInt();
//    	System.out.print("Combien de transactions: ");
//    	int nb_transaction = input.nextInt();
//    	int[][] transaction = new int[nb_transaction][4];
//    	for (int i = 0; i < transaction.length; i++) {
//			System.out.print("Value de transaction " + (i+1) + ": \n");
//			System.out.println("Write ( = 0)  or Read ( = 1):");
//			transaction[i][0] = input.nextInt();
//			System.out.println("Numero de transaction: ");
//			transaction[i][1] = input.nextInt();
//			System.out.println("Ressource manipule: ");
//			transaction[i][2] = input.nextInt();
//			transaction[i][3] = i + 1;
//		}
//    	for (int i = 0; i < transaction.length; i++) {
//			System.out.println("{"+transaction[i][0]+","+transaction[i][1]+","+transaction[i][2]+","+transaction[i][3]+"}");
//		}
		 // An int array.
        int[][] sizes = { {100, 200, 300} };

        // Create an Integer ArrayList.
        ArrayList<Integer> list = new ArrayList<>();
        // Loop over our array and add each element separately.
        for (int[] element : sizes) {
            System.out.println(element[0]);
        }

        // The final list.
        System.out.println(list);
		
	}

}
