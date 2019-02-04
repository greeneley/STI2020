package geometrie;

public class TestTP {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/* Regle: texture et couleur de la Geometrique
		 * Polygone: ("Rouge","Polygone")
		 * Rectangle: ("Jaune","Rectangle")
		 * Quadrilater: ("Gris","Quadrilater")
		 * Triangle: ("Bleu","Triangles")
		 * Pentagone: ("Violet","Pentagone")
		 * Conique: ("Blanc","Conique")
		 * Cercle: ("Noir","Cercle")
		 * Ellipse: ("Orange","Ellipse")
		 */
		Point p1 = new Point(5.1, 2.0, "A");
		Point p2 = new Point(8.1,9.3,"B");
		Point p3 = new Point (1.1,6.0, "C");
		Point p4 = new Point (3.8,7.5, "D");
		
		System.out.println(p1 + "  " + p2 );
		System.out.println("Distance " + p1.distance(p2) );
		/** Creer un Segment à partir de deux point et afficher la longueur de celui-ci
		 * 
		 */
		Segment AB = new Segment(p1, p2);
		Segment BC = new Segment(p2, p3);
		Segment CD = new Segment(p3, p4);
		Segment DA = new Segment(p4, p1);
		System.out.println(AB.toString()+" Longuer :"+AB.longueur());
		System.out.println(BC.toString()+" Longuer :"+BC.longueur());
		System.out.println(CD.toString()+" Longuer :"+CD.longueur());
		System.out.println(DA.toString()+" Longuer :"+DA.longueur());
		
		/* Instancier un Quadrilater à partir de 4 segments et afficher son périmètre
		 * 
		 */
		
		Quadrilatere ABCD = new Quadrilatere(p1, p2, p3, p4,"Gris","Quadrilater",1);
		System.out.println("Pétrimètre :"+ABCD.getPerimetre());
		System.out.println(ABCD.toString());
	   
	    /** Créer un rectangle à partir de deux points
	     * 
	     */
		Rectangle r = new Rectangle(p1, p2, "Rectangle", "Jaune",2);
		r.dessiner(4);
		r.dessiner();
		Point p = new Point();
		r.dessiner(p);
		/* Exo4.c: Calcul du perimetre par deux classes: Quadrilater et Rectangle
		 * 
		 */
		Quadrilatere quad = new Quadrilatere("Gris","Quadrilatere",1);
		double perquad = quad.getPerimetre();
		Rectangle rect =new Rectangle("Jaune","Rectangle",2);
		double perrect = rect.getPerimetre();
		/* exo4.e: 
		 * 
		 */
		System.out.println("========Debut Exo4.e==========");
		FigureGeometrique [] listFig = new FigureGeometrique[3];
		listFig[0] = new Rectangle("Jaune","Rectangle",2);
		listFig[1] = new Quadrilatere("Gris","Quadrilatere",1);
		listFig[2] = new Cercle("Noir","Cercle",3);
		for (int i=0;i<=2;i++) {
			listFig[i].dessiner();
			}
		System.out.println ("Perimetre d'un rectangle:" + ((Rectangle)listFig[0]).getPerimetre()); 
		System.out.println("========Final Exo4.e==========");
		/*Exo4.f
		 * 
		 */
		//System.out.println("======Debut Exo4.f==========");
		//Quadrilatere qua = new Rectangle("Jaune","Rectangle"); 
		//Rectangle rec = new Quadrilatere("Gris","Quadrilatere"); 
		//System.out.println("========Final Exo4.f==========");
		/* Exo4. h
		 * Regle: Quadrilater: code=1; Rectangle code = 2 ; Cercle code = 3;
		 * 
		 */
		System.out.println("========Debut Exo4.h==========");

		for(int i=0;i<=2;i++){
			System.out.println(listFig[i].code);
		}
		System.out.println("========Final Exo4.h==========");
		/* Exo5.c
		 * 
		 */
		System.out.println("========Debut Exo5.c==========");
		quad.dessin();
		System.out.println("========Final Exo5.c==========");

	}

}
