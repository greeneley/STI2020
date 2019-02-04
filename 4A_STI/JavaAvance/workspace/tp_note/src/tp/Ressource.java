package tp;

import java.util.ArrayList;

public class Ressource {

	public ArrayList<String> chaine = new ArrayList<String>();
	public Ressource() {
	}
	public Ressource(ArrayList<String> r) {
		this.chaine = r;
	}
	public ArrayList<String> getChaine() {
		return chaine;
	}
	public void setChaine(ArrayList<String> chaine) {
		this.chaine = chaine;
	}
	
}
