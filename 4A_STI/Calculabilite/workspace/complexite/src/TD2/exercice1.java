package TD2;

import org.chocosolver.solver.Model;
import org.chocosolver.solver.Solution;
import org.chocosolver.solver.variables.IntVar;

public class exercice1 {
	
    public void modelAndSolve(){
        int n = 8; // On a 8 dames
        /*
         * D�clar� le Model
         */
        Model model = new Model(n + "-xxxx problem"); //D�clar� le Model
        IntVar[] vars = new IntVar[n];
        for(int q = 0; q < n; q++){
            vars[q] = model.intVar("Q_"+q, 1, n); // d�clar� le domaine de chacun variable Dc[i] = [1,8]
        }
        /*
         * Ici on d�clare des contraints 
         */
        for(int i  = 0; i < n-1; i++){
            for(int j = i + 1; j < n; j++){
                model.arithm(vars[i], "!=",vars[j]).post();  // 2 dames ne sont pas sur la meme lignes
                model.arithm(vars[i], "!=", vars[j], "-", j - i).post(); // 2 dames ne sont pas sur la meme diago 
                model.arithm(vars[i], "!=", vars[j], "+", j - i).post(); // 2 dames ne sont pas sur la meme diago
            }
        }
        System.out.println(model.toString());
        // Ici model trouve la solution 
        Solution solution = model.getSolver().findSolution();
        if(solution != null){
            System.out.println(solution.toString());
        }
    }

    public static void main(String[] args) {
        new exercice1().modelAndSolve();
    }
}

