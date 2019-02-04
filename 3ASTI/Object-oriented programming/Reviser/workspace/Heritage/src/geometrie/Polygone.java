package geometrie;

public class Polygone extends FigureGeometrique{
	public void message(){
		System.out.println("c'est la polygone");
	}
	public Polygone(String newCouleur,String newTexture, int newcode){
		super(newCouleur,newTexture,newcode);
	}
	//override
	public String toString() {
		// TODO Auto-generated method stub
		return texture;
	}
	
	
}
