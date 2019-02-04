package tp;

import java.util.ArrayList;

public class Redacteur extends Thread {
		private Integer index ;
		private String nouvel_chaine; //  donner cette nouvel_chaine a` ressource r1 en contenant son nom (INDEX)
		private Ressource lock = new Ressource();
		public Redacteur() {}
		
		public Ressource getLock() {
			return lock;
		}
		public Redacteur(Integer index, Ressource r1, String nouvel_chaine) {
			this.lock = r1;
			this.nouvel_chaine = nouvel_chaine + "_" + index; // contenant 
			this.index = index;
		}
		public void run() {
			for(int i = 0; i < 10; i++) {
				synchronized (lock) {
					// ================================
					// =>>>> Prendre la ressource <<<<=
					// ================================
					Ressource res2 = new Ressource();
					res2 = this.lock;
					// ================================
					// =>>>> MODIFIER LA RESSOURCE <<<<=
					// ================================
					System.out.println("Redacteur: "+ this.index+ " Iteration: " + i +" Chaine: "+ res2.getChaine());
					ArrayList<String> new_chaine = new ArrayList<String>(); // ON CREE UNE NOUVELLE ARRAY POUR AJOUTER LE nouvel_chaine
					new_chaine = res2.getChaine(); 
					new_chaine.add(nouvel_chaine); // AJOUTER 
					res2.setChaine(new_chaine);
					// ================================
					// =>>>> LIBERER LA RESSOURCE<<<<=
					// ================================
					System.gc(); 
					// ================================
					// =>>>>ATTENDRE 3s <<<<=
					// ================================
					try {
						Thread.sleep(3000);
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			}
		}
}
