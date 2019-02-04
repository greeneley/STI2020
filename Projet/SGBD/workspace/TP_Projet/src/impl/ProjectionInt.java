package impl;


import operateurs.Projection;
import stockage.Nuplet;

public class ProjectionInt implements Projection {

	/*
	 * @param Nuplet t
	 * @param atts: des columnes projections 
	 */
	@Override
	public Nuplet[] project(Nuplet[] t, int[] atts) {
		// TODO Auto-generated method stub
		NupletInt[] tab = new NupletInt[t.length];
		for (int i=0; i< t.length; i++) {
			tab[i] = new NupletInt(atts.length);
			for (int j=0; j < atts.length; j++) {
				tab[i].putAtt(j, t[i].getAtt(atts[j]));
			}
		}
		return tab;
	}

}
