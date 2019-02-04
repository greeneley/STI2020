package stockage;

public interface Nuplet {

	/**
	 * 
	 * @param i position de l'attribut
	 * @return valeur de l'attribut
	 */
	public Object getAtt(int i); // lay nhung gia tri o cot co index la i
	
	public void putAtt(int i, Object o);
	
	public int size();
	
	public String toString();
}
