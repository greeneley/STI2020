package TD2;

import org.chocosolver.solver.Model;
import org.chocosolver.solver.Solution;
import org.chocosolver.solver.variables.IntVar;
public class exercice2 {
	public void modelAndSolve() {
		Model model = new Model("Ordonnancement");
		IntVar[] deb = new IntVar[10];
		/*
		 *  ATTENTION: 
		 *  A <=> deb_0
		 *  B <=> deb_1
		 *  ...
		 *  J <=> deb_9		
		 */
		for(int q = 0; q < 10; q++){
            deb[q] = model.intVar("deb_"+q, 0, 15); // d�clar� le domaine de chacun variable Dc[i] = [1,8]
        }
		// des contrains
		model.arithm(deb[1], ">=", deb[0], "+", 5).post();
		model.arithm(deb[2], ">=", deb[0], "+", 5).post();
		model.arithm(deb[3], ">=", deb[0], "+", 5).post();
		model.arithm(deb[4], ">=", deb[1], "+", 4).post();
		model.arithm(deb[5], ">=", deb[2], "+", 3).post();
		model.arithm(deb[6], ">=", deb[2], "+", 3).post();
		model.arithm(deb[5], ">=", deb[3], "+", 2).post();
		model.arithm(deb[7], ">=", deb[4], "+", 1).post();
		model.arithm(deb[8], ">=", deb[5], "+", 5).post();
		model.arithm(deb[8], ">=", deb[6], "+", 4).post();
		model.arithm(deb[9], ">=", deb[7], "+", 3).post();
		model.arithm(deb[9], ">=", deb[8], "+", 2).post();
		
//		System.out.println(model.toString());
		Solution solution = model.getSolver().findSolution();
        if(solution != null){
            System.out.println(solution.toString());
        }
	}
	public static void main(String[] args) {
        new exercice2().modelAndSolve();
    }
}
