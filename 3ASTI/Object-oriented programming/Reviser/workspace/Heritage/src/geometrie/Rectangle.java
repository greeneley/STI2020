package geometrie;

public class Rectangle extends Quadrilatere {
	public void message(){
		System.out.println("Constructeur de Rectangle");
	}
	/** Cr�er un constructeur dans la classe Rectangle qui permet d�instancier un
	 *  rectangle non trivial � partir de deux points 
	 *  (sommets oppos�s du rectangle � on fait l�hypoth�se que les segments
	 *   du rectangle sont parall�les aux axes du rep�re)
	 * 
	 */
	private Segment[] lesSegments = new Segment[4];
	public Point p1;
	public Point p2;
	public Rectangle(Point p1,Point p2,String newCouleur, String newTexture,int newcode){
		super(p1,p2,new Point(p2.getX(), p1.getY(),"E"),new Point(p1.getX(), p2.getY(),"F"),newCouleur,newTexture,2);	
		
	}
	public Rectangle(String newCouleur, String newTexture,int newcode){
		super(newCouleur,newTexture,2);
		lesSegments[0] = new Segment(new Point(),new Point());
		lesSegments[1] = new Segment(new Point(),new Point());
		lesSegments[2] = new Segment(new Point(),new Point());
		lesSegments[3] = new Segment(new Point(),new Point());
	}
	public Point getP1() {
		return p1;
	}

	public void setP1(Point p1) {
		this.p1 = p1;
	}

	public Point getP2() {
		return p2;
	}

	public void setP2(Point p2) {
		this.p2 = p2;
	}

	public double getPerimetre(){
		System.out.println("===================");
		Quadrilatere petrimetre = new Quadrilatere("Gris","Quadrilatere",1);
		System.out.println("Calcul du p�rimetre d'un rectangle (de Rectangle)");
		return petrimetre.getPerimetre();
	}
	
	public void dessiner(){
		System.out.println("Dessin d'un rectangle");
	}

	public void dessiner(Point p){
		System.out.print("Dessiner d'une figure geometrique\n");
	}
}
