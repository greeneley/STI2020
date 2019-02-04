package TD2;

import java.util.Scanner;

import org.chocosolver.solver.Model;
import org.chocosolver.solver.Solution;
import org.chocosolver.solver.variables.IntVar;
public class exercice3 {
	private int[][] transaction;
	private int ressource;
	
	public exercice3(int ressource, int[][] transaction) {
		super();
		this.transaction = transaction;
		this.ressource = ressource;
	}

	public void modelAndSolve() {

		int n = this.ressource;
		Model model = new Model("Serialisabilite");
		IntVar[] T = new IntVar[n];
		
		for(int q = 0; q < n ; q++){
            T[q] = model.intVar("T_"+q, 1, n); 
        }
		int[][] transaction = this.transaction;
		// Contraint 1: T[i] != T[j]
		for(int i  = 0; i < n-1; i++){
			for(int j = i + 1; j < n; j++){
				model.arithm(T[i], "!=", T[j]).post();
			}
		}
		// Contraint 2
		for(int i = 0; i < transaction.length; i++) {
			for(int j = 0; j < transaction.length; j++) {
				if ( i != j) {
					if(transaction[i][2] == transaction[j][2]) // 2 operations sont meme ressources;
						{
						if((transaction[i][0] == 1 && transaction[j][0] == 1) || transaction[i][3] < transaction[j][3]) {
							model.arithm(T[transaction[i][1] - 1], "<", T[transaction[j][1] - 1]).post(); // T[i] < T[j]
						}
					}
				}
			}
		}

		Solution solution = model.getSolver().findSolution();
        if(solution != null){
            System.out.println(solution.toString());
        }
	}
	public static void main(String[] args) {
//		==========================================
//		PARTIE 1: SAISIR 
//		long start = System.currentTimeMillis(); 
//		Scanner input = new Scanner(System.in);	
//    	System.out.print("Combien de transactions: ");
//    	int ressource = input.nextInt();
//    	System.out.print("Combien d'operations : ");
//    	int nb_transaction = input.nextInt();
//    	int[][] transaction = new int[nb_transaction][4];
//    	for (int i = 0; i < transaction.length; i++) {
//			System.out.print("Value d'operation " + (i+1) + ": \n");
//			System.out.println("Write ( = 0)  or Read ( = 1):");
//			transaction[i][0] = input.nextInt();
//			System.out.println("Numero d'operation: ");
//			transaction[i][1] = input.nextInt();
//			System.out.println("Ressource manipule: ");
//			transaction[i][2] = input.nextInt();
//			transaction[i][3] = i + 1;
//		}
//    	input.close();
//    	System.out.println("Transaction: ");
//    	for (int i = 0; i < transaction.length; i++) {
//			System.out.println("{"+transaction[i][0]+","+transaction[i][1]+","+transaction[i][2]+","+transaction[i][3]+"}");
//		}
		
		//========================================
		// PARTIE 2: TESTER ENNONCE
		long start = System.currentTimeMillis(); 
		int ressource = 5;
		int[][] transaction = {{0,1,1,1},{1,2,1,2},{0,1,2,3},{0,3,3,4},{1,2,3,5},{1,4,2,6},{0,2,4,7},{0,4,5,8},{1,5,4,9},{0,5,5,10}};
		//========================================
		exercice3 test = new exercice3(ressource, transaction);
        test.modelAndSolve();
        System.out.println("Temps d'ex�cution: "+(System.currentTimeMillis()-start)); 
    }
}
