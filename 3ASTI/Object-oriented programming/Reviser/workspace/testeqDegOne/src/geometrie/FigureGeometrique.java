package geometrie;


public abstract class FigureGeometrique {
	protected String couleur;
	protected String texture;
	public int zone;
	public int code;
	
	
	public FigureGeometrique(String newCouleur,String newTexture,int newcode){
		couleur=newCouleur;
		texture=newTexture;
		code=newcode;	
	}

	public void dessiner(int zone){
		System.out.print("Dessin de la " + zone +" zone d'une figure géométrique \n" );
	}
	public void dessiner(){
		System.out.print("Dessin d'une figure géométrique \n" );
	}
	public abstract String toString();
}
