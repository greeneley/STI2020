package test;

import stockage.*;
import impl.*;
import operateurs.Jointure;
import operateurs.Projection;
import operateurs.Restriction;

public class Main {
	
	public static final int datasetSize = 100;
	public static final int nupletSize = 10;

	public static void main(String[] args){
		
		// Generation des donnees
		Nuplet[] tab = new NupletInt[datasetSize];
		for(int i=0;i<datasetSize;i++){
			tab[i] = new NupletInt(nupletSize);
			for(int j=0;j<nupletSize;j++){
				tab[i].putAtt(j, (byte)(j+i));
			}
		}

		// Implémentation avec Table
		
		System.out.println("------------------------------------------------");	
		System.out.println("Création d'une table");
		Table t = new TableInt("table2", nupletSize);
		for(int i=0;i<datasetSize;i++){
			t.put(tab[i]);
			}
		System.out.println("Lecture d'une table");
		for(int i=0;i<datasetSize;i++){
			System.out.println(t.get(i).toString());
			}
		// Attribut la number colonne
		// Utilisation de getByAtt
		System.out.println("Test GetByAtt");
		Nuplet[] res = t.getByAtt(5, (byte)50);
		for(Nuplet n : res)
			System.out.println(n.toString());
		//  Utilisation de fullScan
		System.out.println("======= FULL SCAN =======");
		Nuplet[] fullscan = t.fullScan();
		for(Nuplet n : fullscan)
			System.out.println(n.toString());
		// Utilisation de Restriction 
		System.out.println("======= RESTRICTION ======");

		Restriction testRestriction = new RestrictionInt();
		System.out.println("Test Egalite");
		Nuplet[] testEgalite = testRestriction.egalite(fullscan, 3, (byte) 50);
		for(Nuplet n : testEgalite)
			System.out.println(n.toString());
		System.out.println("Test Superieur");
		Nuplet[] testSuperieur = testRestriction.superieur(fullscan, 3, (byte) 50);
		for(Nuplet n : testSuperieur)
			System.out.println(n.toString());
		System.out.println("Test Inferieur");
		Nuplet[] testInferieur = testRestriction.inferieur(fullscan, 3, (byte) 50);
		for(Nuplet n : testInferieur)	
			System.out.println(n.toString());
	
		// Utilisation de Projection
		System.out.println("========= PROJECTION ========");
		Projection testProjection = new ProjectionInt();
		int[] atts = {1,2,3};
		Nuplet[] testProj = testProjection.project(fullscan, atts);
		for(Nuplet n : testProj)
			System.out.println(n.toString());
		
		// Créer un nouveau Nuplets
		int[] atts2 = {2,3,4};
		Nuplet[] testProj2 = testProjection.project(fullscan, atts2);
		
		
		// Utilisation de JointureBI
		System.out.println("======= JOINTURE BI ======");
		Jointure testJointure = new JointureBI();
		Nuplet[] testJointureBI = testJointure.jointure(testProj, testProj2, 0, 0);
		for(Nuplet n : testJointureBI) {				
			System.out.println(n.toString());
		}
//
//		
		// Utilisation de JointureH
		System.out.println("====== JOINTURE HACHAGE =======");
		System.out.println("JointureH");
		Jointure testJointure_Hash_Join = new JointureH();
		Nuplet[] testJointureH = testJointure_Hash_Join.jointure(testProj, testProj2, 0, 0);
		for(Nuplet n : testJointureH) 				
			System.out.println(n.toString());

		// Utilisation de JointureS
		System.out.println("======= JOINTURE MERGE SORT =======");
		System.out.println("JointureS");
		Jointure testJointure_Sort_Merge = new JointureS();
		Nuplet[] testJointureS = testJointure_Sort_Merge.jointure(testProj, testProj2, 0, 0);
		for(Nuplet n : testJointureS) 				
			System.out.println(n.toString());
//		
		// Implementation exemple
		System.out.println("===== PLAN D'EXECUTION =====");
		int[] value_1 = {1,2,3}; // R(A,B,C) <=> R(1,2,3)
		int[] value_2 = {4,5,6}; // S(D,E,F) <=> S(4,5,6)
		Nuplet[] R  = testProjection.project(fullscan, value_1);
		Nuplet[] S  = testProjection.project(fullscan, value_2);
		Jointure testJointure_BI = new JointureBI();
		Jointure testJointure_H = new JointureH();
		Jointure testJointure_S = new JointureS();
		//	arbre 1 + BI => plan 1
		//	arbre 2 + BI => plan 2
		//	arbre 3 + BI => plan 3
		//	arbre 1 + H => plan 4
		//	arbre 2 + H => plan 5
		//	arbre 3 + H => plan 6


		System.out.println("Plan 1");
		final long start_1 = System.nanoTime();
		Nuplet[] testJointureH_Plan_1 = testJointure_BI.jointure(R, S, 0, 1); // R.A = S.E => A B C D F ; 
		Restriction testRestriction_Plan_1 = new RestrictionInt();
		Nuplet[] testSuperieur_Plan_1 = testRestriction_Plan_1.superieur(testJointureH_Plan_1, 1, (byte) 15);
		Projection testProjection_Plan_1 = new ProjectionInt();
		int[] atts_Plan_1 = {2};
		Nuplet[] testProj_Plan_1 = testProjection_Plan_1.project(testSuperieur_Plan_1, atts_Plan_1);
		final long end_1 = System.nanoTime();
		System.out.println("Temps d'exécution:: " + ((end_1 - start_1) ) +" ns");
		
		
		System.out.println("Plan 2");
		final long start_2 = System.nanoTime();
		Nuplet[] testJointureH_Plan_2 = testJointure_H.jointure(R, S, 0, 1); // R.A = S.E => A B C D F ; 
		Restriction testRestriction_Plan_2 = new RestrictionInt();
		Nuplet[] testSuperieur_Plan_2 = testRestriction_Plan_2.superieur(testJointureH_Plan_2, 1, (byte) 15);
		Projection testProjection_Plan_2 = new ProjectionInt();
		int[] atts_Plan_2 = {2};
		Nuplet[] testProj_Plan_2 = testProjection_Plan_2.project(testSuperieur_Plan_2, atts_Plan_2);
		final long end_2 = System.nanoTime();
		System.out.println("Temps d'exécution:: " + ((end_2 - start_2) +" ns") );
		
		
		System.out.println("Plan 3");
		final long start_3 = System.nanoTime();
		Nuplet[] testJointureH_Plan_3 = testJointure_S.jointure(R, S, 0, 1); // R.A = S.E => A B C D F ; 
		Restriction testRestriction_Plan_3 = new RestrictionInt();
		Nuplet[] testSuperieur_Plan_3 = testRestriction_Plan_3.superieur(testJointureH_Plan_3, 1, (byte) 15);
		Projection testProjection_Plan_3 = new ProjectionInt();
		int[] atts_Plan_3 = {2};
		Nuplet[] testProj_Plan_3 = testProjection_Plan_3.project(testSuperieur_Plan_3, atts_Plan_3);
		final long end_3 = System.nanoTime();
		System.out.println("Temps d'exécution:: " + ((end_3 - start_3) +" ns") );

		
		System.out.println("Plan 4");
		final long start_4 = System.nanoTime();
		Restriction testRestriction_Plan_4 = new RestrictionInt();
		Nuplet[] testSuperieur_Plan_4 = testRestriction_Plan_4.superieur(R, 1, (byte) 15);
		Nuplet[] testJointureH_Plan_4 = testJointure_BI.jointure(testSuperieur_Plan_4, S, 0, 1);
		Projection testProjection_Plan_4 = new ProjectionInt();
		int[] atts_Plan_4 = {2};
		Nuplet[] testProj_Plan_4 = testProjection_Plan_4.project(testJointureH_Plan_4, atts_Plan_4);
		final long end_4 = System.nanoTime();
		System.out.println("Temps d'exécution: " + ((end_4 - start_4) ) +" ns");
		
		
		System.out.println("Plan 5");
		final long start_5 = System.nanoTime();
		Restriction testRestriction_Plan_5 = new RestrictionInt();
		Nuplet[] testSuperieur_Plan_5 = testRestriction_Plan_5.superieur(R, 1, (byte) 15);
		Nuplet[] testJointureH_Plan_5 = testJointure_H.jointure(testSuperieur_Plan_5, S, 0, 1);
		Projection testProjection_Plan_5 = new ProjectionInt();
		int[] atts_Plan_5 = {2};
		Nuplet[] testProj_Plan_5 = testProjection_Plan_5.project(testJointureH_Plan_5, atts_Plan_5);
		final long end_5 = System.nanoTime();
		System.out.println("Temps d'exécution: " + ((end_5 - start_5) )+ " ns" );
		
		
		
		System.out.println("Plan 6");
		final long start_6 = System.nanoTime();
		Restriction testRestriction_Plan_6 = new RestrictionInt();
		Nuplet[] testSuperieur_Plan_6 = testRestriction_Plan_6.superieur(R, 1, (byte) 15);
		Nuplet[] testJointureH_Plan_6 = testJointure_S.jointure(testSuperieur_Plan_6, S, 0, 1);
		Projection testProjection_Plan_6 = new ProjectionInt();
		int[] atts_Plan_6 = {2};
		Nuplet[] testProj_Plan_6 = testProjection_Plan_6.project(testJointureH_Plan_6, atts_Plan_6);
		final long end_6 = System.nanoTime();
		System.out.println("Temps d'exécution: " + ((end_6 - start_6) )+ " ns" );
		
		
		
		
		System.out.println("======= METTRE A JOUR =======");	
		System.out.println("Création d'une table t1");
		Table t1 = new TableInt("table1", nupletSize);
		for(int i=0;i<datasetSize;i++){
			t1.put(tab[i]);
		}
		System.out.println("===== LECTURE VIA FULLSCAN =====");
		for(Nuplet n : t1.fullScan())
			System.out.println(n.toString());
		
		System.out.println("\n===== INSERT =====");
		Nuplet newNuplet = new NupletInt(new byte[] {0,50,2,3,4,5,6,7,8,9});
		System.out.println("\n t1.insert(nouveau_nuplet)");
		t1.insert(newNuplet);
		for(Nuplet n : t1.fullScan())
			System.out.println(n.toString());
		
		System.out.println("\n===== UPDATE =====");
		System.out.println("\nt1.update(1, 50, 51);");
		t1.update(1, (byte) 50, (byte) 51);
		for(Nuplet n : t1.fullScan())
			System.out.println(n.toString());
		
		System.out.println("\n===== DELETE =====");
		System.out.println("\nt1.delete(1, 51);");
		t1.delete(1, (byte) 51);
		for(Nuplet n : t1.fullScan())
			System.out.println(n.toString());
		}
	
	}

