package geometrie;

public class Conique extends FigureGeometrique{
	public void message(){
		System.out.println("C'est le conique");
	}
	public Conique(String newCouleur, String newTexture,int newcode){
		super(newCouleur,newTexture,newcode);
	}
	public String toString() {
		// TODO Auto-generated method stub
		return texture;
	}
}
