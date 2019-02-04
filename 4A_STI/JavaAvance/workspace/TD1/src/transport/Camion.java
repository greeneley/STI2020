package transport;

public class Camion implements Vehicule {
	
	private String nom_vehicule;
	public Camion(String nom_vehicule){
		this.nom_vehicule = nom_vehicule;
	}
	@Override
	public String toString() {
		return "Camion [nom_vehicule=" + nom_vehicule + "]";
	}
}
